#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::string;

static WFFacilities::WaitGroup waitGroup(1);

void sigHandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

void redisCallback(WFRedisTask* redisTask) {
    // 检查报错
    int state = redisTask->get_state();  // 获取状态
    int error = redisTask->get_error();  // 获取errno
    switch (state) {
        case WFT_STATE_SYS_ERROR:  // 系统错误
            cerr << "system error: " << strerror(error) << "\n";
            break;
        case WFT_STATE_DNS_ERROR:  // 网络信息错误
            cerr << "DNS error: " << gai_strerror(error) << "\n";
            break;
        case WFT_STATE_SUCCESS:  // 成功
            break;
    }

    // 先获取redis的结果
    protocol::RedisResponse* resp = redisTask->get_resp();

    // 默认构造一个result对象，将来可以存储redis指令的存储结果
    protocol::RedisValue result;

    resp->get_result(result);  // 获取指令的执行结果

    // 指令是否执行成功
    if (result.is_error()) {
        cerr << "Redis error!\n";
        state = WFT_STATE_TASK_ERROR;
    }

    if (state != WFT_STATE_SUCCESS) {
        cerr << "Failed.Please press ctrl + C to exit.\n";
        return;
    }

    // 展示读到的结果
    if (result.is_string()) {
        cout << "result is " << result.string_value() << "\n";
    }
}
int main() {
    signal(SIGINT, sigHandler);

    WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379", 10, redisCallback);
    // 只能设置请求，不能设置响应
    protocol::RedisRequest* req = redisTask->get_req();
    req->set_request("SET", {"58key", "littlemorre"});

    redisTask->start();

    waitGroup.wait();
    cout << "finished!\n";
    return 0;
}