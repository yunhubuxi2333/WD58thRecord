#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>
using std::cerr;
using std::cout;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";  // 尽量避免使用endl
    waitGroup.done();
}
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
    protocol::RedisValue
        result;  // 默认构造一个result对象，将来可以存储redis指令的执行结果
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
        cout << "result is " << result.string_value() << "\n";
    } else if (result.is_array()) {
        cout << "result is array\n";
        for (int i = 0; i < result.arr_size(); ++i) {
            cout << "i = " << i
                 << " value =  " << result.arr_at(i).string_value() << "\n";
        }
    }
}
int main() {
    signal(SIGINT, sighandler);
    WFRedisTask* redisTask =
        WFTaskFactory::create_redis_task("redis://127.0.0.1:6379", 10,
                                         // nullptr
                                         redisCallback);
    protocol::RedisRequest* req = redisTask->get_req();

    // req->set_request("GET",{"58key"});
    req->set_request("HGETALL", {"58table"});
    redisTask->start();
    waitGroup.wait();
    cout << "finished!\n";
}