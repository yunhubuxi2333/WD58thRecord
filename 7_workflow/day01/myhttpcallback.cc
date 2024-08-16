#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>

using std::cout;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

void httpCallback(WFHttpTask* httpTask) {
    cout << "httpCallback is running...\n";
    protocol::HttpResponse* resp = httpTask->get_resp();
}

int main() {
    signal(SIGINT, sighandler);
    WFHttpTask* httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com", 10, 10, httpCallback);
    protocol::HttpRequest* req = httpTask->get_req();
    req->add_header_pair("Agent", "huwentao");
    httpTask->start();

    waitGroup.wait();
    cout << "finished!\n";
}