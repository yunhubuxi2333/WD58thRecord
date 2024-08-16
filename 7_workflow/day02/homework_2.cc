#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::string;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";  // 尽量避免使用endl
    waitGroup.done();
}
// Redis任务的回调函数
void redisCallback(WFRedisTask* redisTask) {
    // 检查报错
    int state = redisTask->get_state();  // 获取状态
    int error = redisTask->get_error();  // 获取errno
    switch (state) {
        case WFT_STATE_SYS_ERROR:  // 操作系统层面的错误
            cerr << "system error: " << strerror(error) << "\n";
            break;
        case WFT_STATE_DNS_ERROR:  // 网络信息错误
            cerr << "DNS error: " << gai_strerror(error) << "\n";
            break;
        case WFT_STATE_SUCCESS:
            break;
    }
    // 先获取redis的结果
    protocol::RedisResponse* resp = redisTask->get_resp();
    // 默认构造一个result对象，将来可以存储redis指令的执行结果
    protocol::RedisValue result;
    resp->get_result(result);  // 获取指令执行的结果

    // 指令是否执行成功
    if (result.is_error()) {
        cerr << "Redis error\n";
        state = WFT_STATE_TASK_ERROR;
    }
    if (state != WFT_STATE_SUCCESS) {
        cerr << "Failed. Press Ctrl-C to exit.\n";
        return;
    }

    // 展示读到的结果
    if (result.is_string()) {
        string next_key = result.string_value();
        cout << "Found key :" << next_key << "\n";

        if (next_key == "100") {
            cout << "Final value:" << next_key << "\n";
            return;
        }

        // 继续创建下一个Redis任务，查询下一个key
        WFRedisTask* nextRedisTask = WFTaskFactory::create_redis_task(
            "redis://127.0.0.1:6379", 10, redisCallback);

        // 设置请求命令：GET下一个key
        nextRedisTask->get_req()->set_request("GET", {next_key});

        series_of(redisTask)->push_back(nextRedisTask);

    } else if (result.is_array()) {
        cout << "Error : Value is not a string or key not found.\n";
    }
}
int main() {
    signal(SIGINT, sighandler);
    WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379", 10, redisCallback);

    // 设置请求命令：GET x1
    redisTask->get_req()->set_request("GET", {"x1"});

    redisTask->start();

    waitGroup.wait();
    cout << "finished!\n";
}