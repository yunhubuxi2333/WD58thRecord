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

int main() {
    signal(SIGINT, sighandler);
    WFHttpTask* httpTask =
        WFTaskFactory::create_http_task("http://www.baidu.com", 10, 10, nullptr);
    protocol::HttpRequest* req = httpTask->get_req();
    req->add_header_pair("Agent", "huwentao");
    httpTask->start();

    waitGroup.wait();
    cout << "finished!\n";
}