#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>
#include <string>

using std::cout;
using std::string;

static WFFacilities::WaitGroup waitGroup(1);

// Redis任务的回调函数
void redisCallback(WFRedisTask* redisTask) {
    if (redisTask->get_state() == WFT_STATE_SUCCESS) {
        cout << "HTML content successfully stored in Redis.\n";
    } else {
        cout << "Failed to store HTML content in Redis.\n";
    }
}

// HTTP任务的回调函数
void httpCallback(WFHttpTask* httpTask) {
    if (httpTask->get_state() == WFT_STATE_SUCCESS) {
        protocol::HttpResponse* resp = httpTask->get_resp();
        const void* body;
        size_t body_len;

        // 获取HTTP响应体的内容（HTML）
        resp->get_parsed_body(&body, &body_len);
        string html_content(static_cast<const char*>(body), body_len);

        // 创建Redis任务，将HTML内容存储到Redis中
        WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
            "redis://127.0.0.1:6379", 10, redisCallback);

        // 设置Redis命令：SET www.taobao.com <HTML content>
        redisTask->get_req()->set_request("SET",
                                          {"www.taobao.com", html_content});

        // 启动Redis任务
        redisTask->start();
    } else {
        cout << "Failed to fetch HTML content from the website.\n";
    }
}

void sigHandler(int signum) {
    cout << "Terminating...\n";
    waitGroup.done();
}

int main() {
    signal(SIGINT, sigHandler);

    // 创建HTTP任务，访问淘宝网站
    WFHttpTask* httpTask = WFTaskFactory::create_http_task(
        "http://www.taobao.com", 10, 3, httpCallback);

    // 启动HTTP任务
    httpTask->start();

    // 等待任务完成
    waitGroup.wait();
    cout << "Finished.\n";
    return 0;
}
