#include <signal.h>
#include <wfrest/HttpServer.h>
#include <workflow/WFFacilities.h>

#include <iostream>
using std::cout;
using std::map;
using std::string;
// static 全局变量or函数 只在本文件里面生效
static WFFacilities::WaitGroup waitGroup(1);
// static 局部变量 这是静态变量
// static 类成员 和类相关的成员
void sighandler(int signum) {
    cout << "done!\n";  // 尽量避免使用endl
    waitGroup.done();
}
int main() {
    signal(SIGINT, sighandler);
    wfrest::HttpServer server;
    server.GET(
        "/hello", [](const wfrest::HttpReq* req, wfrest::HttpResp* resp) {
            cout << "hello\n";
            // resp->append_output_body("hello"); //基类的方法
            resp->String("<html><p><H1>Hello</H1></p><p>World</p></html>");
            // 派生类的方法
            resp->headers["Content-Type"] = "text/html";
            // MIME类型
        });
    server.GET("/world",
               [](const wfrest::HttpReq* req, wfrest::HttpResp* resp) {
                   cout << "world\n";
                   resp->String("<html><p>World</p></html>");
                   resp->headers["Content-Type"] = "text/html";
               });

    server.GET("/login",
               [](const wfrest::HttpReq* req, wfrest::HttpResp* resp) {
                   // 部署静态资源服务器
                   resp->File("postform.html");
               });

    server.POST("/login", [](const wfrest::HttpReq* req, wfrest::HttpResp* resp,
                             SeriesWork* series) {
        // 解析urlencoded类型的报文体
        map<string, string> mapForm = req->form_kv();
        for (auto pair : mapForm) {
            cout << "key = " << pair.first << " value = " << pair.second
                 << "\n";
        }
        string password = mapForm["password"];
        WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
            "redis://127.0.0.1:6379", 10,
            [resp, password](WFRedisTask* redisTask) {
                protocol::RedisResponse* respRedis = redisTask->get_resp();
                protocol::RedisValue result;
                respRedis->get_result(result);
                if (result.is_string() && result.string_value() == password) {
                    resp->String("success");
                } else {
                    resp->String("fail");
                }
            });
        redisTask->get_req()->set_request("HGET",
                                          {"user", mapForm["username"]});
        series->push_back(redisTask);
    });

    server.GET("/upload",
               [](const wfrest::HttpReq* req, wfrest::HttpResp* resp) {
                   // 部署静态资源服务器
                   resp->File("upload.html");
               });
    server.POST("/upload", [](const wfrest::HttpReq* req,
                              wfrest::HttpResp* resp) {
        map<string, std::pair<string, string>>& formData = req->form();
        // for(auto pair:formData){
        //     cout << "key = " << pair.first
        //          << " value1 = " << pair.second.first
        //          << " value2 = " << pair.second.second << "\n";
        // }
        int fd = open(formData["file"].first.c_str(), O_RDWR | O_CREAT, 0666);
        write(fd, formData["file"].second.c_str(),
              formData["file"].second.length());
        close(fd);
    });

    // // 192.168.72.128:12345/login?username=niqiu&password=123
    // // server.POST("/login",[](const wfrest::HttpReq *req, wfrest::HttpResp
    // // *resp){
    // // const map<string,string> &queryMap = req->query_list();
    // // for(auto pair:queryMap){
    // //     cout << "key = " << pair.first << " value = " << pair.second <<
    // "\n";
    // // }
    // //});

    if (server.track().start(12345) == 0) {
        // start是非阻塞的
        server.list_routes();
        waitGroup.wait();
        cout << "finished!\n";
        server.stop();
        return 0;
    } else {
        perror("server start fail!");
        return -1;
    }
}