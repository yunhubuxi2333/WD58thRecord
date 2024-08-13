#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/Workflow.h>

#include <iostream>

using std::cerr;
using std::cout;
static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}                

int main() {
    signal(SIGINT, sighandler);
    ParallelTask *parallel = Workflow::create_parallel_work(nullptr);
    vector<string> urls = {
        "https://www.taobao.com",
        "https://www.jd.com",
        "https://www.baidu.com"
    };
    for(int i = 0;i<3;++i){
        WFHttpTask *httpTask = WFTaskFactory::create_http_task(
            urls[i],10,10
            ,nullptr
        );
        SeriesWork *series = Workflow::create_series_work(httpTask,nullptr);
        parallel->add_seri


    }

    waitGroup.wait();
    cout << "finished!\n";
}
