#include <iostream>
#include <mutex>
#include <thread>

using std ::cout;
using std::endl;
using std::mutex;
using std ::thread;

int gCnt = 0;
mutex mtx;  // 创建互斥锁的对象
void threadFunc() {
    for (size_t idx = 0; idx < 10000000; ++idx) {
        mtx.lock();  // 对共享资源加锁
        ++gCnt;
        mtx.unlock();  // 解锁
    }
}

int main() {
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();

    cout << gCnt << endl;

    return 0;
}
