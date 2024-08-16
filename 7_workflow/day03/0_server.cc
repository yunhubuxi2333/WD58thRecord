#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>

#include <iostream>

using std::cerr;
using std::cout;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

void process(WFHttpTask* serverTask) {
    // serverTask是一个特殊的任务：基本工作是用户代码process,基本工作和callback是分离的
    // cout << "i am callback\n";
    // req是客户端发来请求
    protocol::HttpRequest* req = serverTask->get_req();
    // resp是将要回复给客户端的响应
    protocol::HttpResponse* resp = serverTask->get_resp();
    // 从请求中去获取报文体
    const void* body;
    size_t size;
    req->get_parsed_body(&body,&size);
    //设置响应的报文
    resp->append_output_body(body,size);
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
