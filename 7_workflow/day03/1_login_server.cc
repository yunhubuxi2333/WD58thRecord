#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>

using std::cerr;
using std::cout;
using std::string;

struct SericesContext {
    string name;
    string password;
    protocol::HttpResponse* resp;
};
static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

void redisCallback(WFRedisTask* redisTask) {
    protocol::RedisResponse* respRedis = redisTask->get_resp();
    protocol::RedisValue result;
    respRedis->get_result(result);

    // 找到context 提取用户传入的密码
    SericesContext* context =
        static_cast<SericesContext*>(series_of(redisTask)->get_context());

    // redis里面存储了数据库的密码
    if (result.is_string() && result.string_value() == context->password) {
        // 在redisTask的回调中去修改serverTask的响应
        context->resp->append_output_body("Success");
    } else {
        context->resp->append_output_body("fail");
    }
}

void process(WFHttpTask* serverTask) {
    // serverTask是一个特殊的任务：基本工作是用户代码process,基本工作和callback分离的
    //  http:192.168.111.130/login?username=niqiu&password=123
    // req是客户端发来请求
    protocol::HttpRequest* req = serverTask->get_req();
    // resp是将要回复给客户端的响应
    protocol::HttpResponse* resp = serverTask->get_resp();
    // 从请求当中提取 username 和 password
    string uri = req->get_request_uri();
    cout << "uri = " << uri << "\n";
    string nameKV = uri.substr(0, uri.find("&"));
    string passwordKV = uri.substr(uri.find("&") + 1);
    string name = nameKV.substr(nameKV.find("=") + 1);
    string password = passwordKV.substr(passwordKV.find("=") + 1);
    cout << "name = " << name << ", password = " << password << "\n";
    // 申请内存，保存用户名和密码信息，共享给redisTask
    SericesContext* context = new SericesContext;
    context->name = name;
    context->password = password;
    context->resp = resp;
    series_of(serverTask)->set_context(context);
    // 创建一个redis任务，查询
    WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379", 10, redisCallback);
    redisTask->get_req()->set_request("HGET", {"user", name});

    // process是特殊的serverTask的基本工作
    // redisTask会在process执行之后，serverTask的回调之前执行
    series_of(serverTask)->push_back(redisTask);
}

int main() {
    signal(SIGINT, sighandler);
    WFHttpServer server(process);
    if (server.start(12345) == 0) {
        waitGroup.wait();
        cout << "finished!\n";
        server.stop();
        return 0;
    } else {
        perror("server start fail!\n");
        return -1;
    }
}
