#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>

using std::cout;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done\n";  // 尽量避免使用endl
    waitGroup.done();
}

void httpCallback(WFHttpTask* httpTask) {
    cout << "httpCallback is running\n";
    protocol::HttpResponse* resp = httpTask->get_resp();
}

int main() {
    signal(SIGINT, sighandler);
    WFHttpTask* httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com", 10, 10,
        httpCallback  // 这个httpCallback将会在任务的基本工作完成之后，由框架调用
    );                // 给任务对象申请内存并初始化
    protocol::HttpRequest* req = httpTask->get_req();
    req->add_header_pair("Agent", "workflow");  // 给请求加一个首部字段
    httpTask->start();  //  启动任务，异步。把任务交给框架，由框架调度资源运行

    waitGroup.wait();
    cout << "finished\n";
}
