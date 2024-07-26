#include <iostream>
#include <mutex>
#include <thread>

using std ::cout;
using std::endl;
using std::mutex;
using std ::thread;

int gCnt = 0;
mutex mtx;  // 创建互斥锁的对象
mutex mtx2;

// 利用RAII的思想：利用栈对象的生命周期管理资源

class MutexLockGuard {
   public:
    MutexLockGuard(mutex& metx) : _mtx(metx) {
        _mtx.lock();  // 在构造函数中上锁
    }

    ~MutexLockGuard() {
        _mtx.unlock();  // 在析构函数中解锁
    }

   private:
    mutex& _mtx;
};

void threadFunc() {
    for (size_t idx = 0; idx < 10000000; ++idx) {
        MutexLockGuard autoLock(mtx);
        ++gCnt;
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
