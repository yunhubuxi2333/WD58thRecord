#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>

#include "Task.h"
#include "ThreadPool.h"

using std::cout;
using std::endl;
using std::unique_ptr;
  
class MyTask : public Task {
   public:
    void process() override {  
        // MyTask到底执行什么任务
        // 需要根据具体的业务逻辑添加任务
        ::srand(::clock());  // 种随机种子
        int number = ::rand() % 100;
        cout << "MyTask number = " << number << endl;
    }
};

// 1、现在只执行了12个任务，程序就结束了？

// 问题一：添加了20次的任务，但是任务没有执行完，程序就退出了？
// 原因：主线程与工作线程都在执行，但是有可能主线程将任务添加完毕之后，会继续执行stop函数
// 将标志位_isExit设置为了true，此时子线程在执行while循环的时候，不能进入到while循环种，
// 那么就会出现任务没有执行完，程序就退出来了

// 解决方案：在stop函数中添加代码，只要任务执行不完，就让主线程睡眠

// 问题二：任务有时候可以执行完，但是发现程序好像没有退出来？

void test() {
    unique_ptr<Task> ptask(new MyTask());
    // 创建线程池的对象
    ThreadPool pool(4, 10);

    // 启动线程池
    pool.start();

    // 添加任务
    int cnt = 20;
    while (cnt--) {
        pool.addTask(ptask.get());
        cout << "cnt =" << cnt << endl;
    }
    // 关闭线程池
    pool.stop();
}

int main() {
    test();
    return 0;
}