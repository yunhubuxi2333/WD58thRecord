// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h>
// WFHttpServer.h 包含server类的设计
#include <signal.h>
#include <unistd.h>
#include <workflow/WFHttpServer.h>

#include <iostream>
#include <string>
using std::cout;
using std::string;

struct SeriesContext {
    string name;  // 键值对形式
    string password;
    protocol::HttpResponse* resp;  // 决定了回复给客户端的内容
};

// WaitGroup 让某个线程处于等待状态
static WFFacilities::WaitGroup waitGroup(1);

void sigHandler(int signum) {  // 信号处理函数
    cout << "done!\n";
    waitGroup.done();
}

// redisCallback函数处理Redis返回的结果，并根据验证结果向客户端返回success或fail的响应。
void redisCallback(WFRedisTask* redisTask) {
    // 获取redis的执行结果
    protocol::RedisValue result;
    protocol::RedisResponse* resp = redisTask->get_resp();
    resp->get_result(result);

    // 访问context
    SeriesContext* context =
        static_cast<SeriesContext*>(series_of(redisTask)->get_context());
    // 如果result的value对上了，那么返回成功，否则失败
    if (result.is_string() && result.string_value() == context->password) {
        cout << context->name << " success\n";
        context->resp->append_output_body("<html>success</html>");
    } else {
        cout << context->name << " fail\n";
        context->resp->append_output_body("<html>fail</html>");
    }
}

// process函数是每当有HTTP请求到达时被调用的回调函数。它负责解析URL中的用户名和密码，并创建一个Redis任务去验证这些凭据。
void process(WFHttpTask* serverTask) {  // 回复给客户端的响应
                                        // 一定是serverTask的resp决定的
    protocol::HttpRequest* req = serverTask->get_req();  // 发送请求
    string uri = req->get_request_uri();  // 设置变量记录uri
    cout << uri << "\n";
    // /login?username=niqiu&password=123
    string nameKV = uri.substr(0, uri.find("&"));
    string passwordKV = uri.substr(uri.find("&") + 1);
    string name = nameKV.substr(nameKV.find("=") + 1);
    string password = passwordKV.substr(passwordKV.find("=") + 1);
    cout << "name = " << name << ", password = " << password << "\n";
    // 申请一片内存空间，用于序列内的任务共享数据
    SeriesContext* context = new SeriesContext;
    context->name = name;
    context->password = password;
    context->resp = serverTask->get_resp();
    series_of(serverTask)->set_context(context);
    // 创建一个连接到本地Redis的任务，并指定一个回调函数redisCallback，在Redis任务完成后调用该回调。
    WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379", 10, redisCallback);
    // hget 58user niqiu
    redisTask->get_req()->set_request("HGET", {"58user", name});
    series_of(serverTask)->push_back(redisTask);
}

int main() {
    signal(SIGINT, sigHandler);  // 等待信号

    // 在端口12345启动了一个HTTP服务器，当有请求到达时，会调用process函数进行处理。
    WFHttpServer server(process);
    if (server.start(12345) == 0) {
        waitGroup.wait();
        server.stop();
    } else {
        perror("server start failed!");
        return -1;
    }
    cout << "finished!\n";
    return 0;
}