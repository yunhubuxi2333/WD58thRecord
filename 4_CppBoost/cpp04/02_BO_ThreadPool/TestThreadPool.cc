#include <stdlib.h>
#include <time.h>

#include <functional>
#include <iostream>
#include <memory>


#include "ThreadPool.h"

using std::bind;
using std::cout;
using std::endl;
using std::unique_ptr;

class MyTask {
   public:
    void process(int x) {
        // MyTask到底执行什么任务
        // 需要根据具体的业务逻辑添加任务
        ::srand(::clock());  // 种随机种子
        int number = ::rand() % 100;
        cout << ">>BO_threadPool.MyTask number = " << number << endl;
    }
};

void test() {
    unique_ptr<MyTask> ptask(new MyTask());
    // 创建线程池的对象
    ThreadPool pool(4, 10);

    // 启动线程池
    pool.start();

    // 添加任务
    int cnt = 20;
    while (cnt--) {
        pool.addTask(bind(&MyTask::process, ptask.get(), 100));
        cout << "cnt =" << cnt << endl;
    }
    // 关闭线程池
    pool.stop();
}

int main() {
    test();
    return 0;
}