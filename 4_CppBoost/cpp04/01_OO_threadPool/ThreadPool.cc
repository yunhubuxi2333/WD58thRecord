#include "ThreadPool.h"

#include <iostream>

#include "Task.h"

using std::cout;
using std::endl;

ThreadPool::ThreadPool(size_t threadNum, size_t queSize)
    : _threadNum(threadNum),
      _threads(),
      _queSize(queSize),
      _taskQue(_queSize),
      _isExit(false) {}

ThreadPool::~ThreadPool() {}

// 线程池的启动与停止
void ThreadPool::start() {
    // 需要创建出线程（线程创建出来 之后需要执行线程入口函数）
    for (size_t idx = 0; idx != _threadNum; ++idx) {
        // 创建的线程
        _threads.push_back(thread(&ThreadPool ::doTask, this));
    }
}

void ThreadPool::stop() {
    // 需要保证任务执行完毕之后，主线程才能继续向下执行
    // 否则就卡在此处
    while (!_taskQue.isEmpty()) {
        // 让主线程在此处睡眠1s
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // 线程池要退出来了，可以将标志位设置为true
    // 然后回收工作线程
    _isExit = true;

    // 需要将所有可能在_notEmpty条件变量上的线程唤醒
    //  _notEmpty.
    _taskQue.wakeup();

    for (auto& th : _threads) {
        th.join();  // 回收子线程
    }
}

// 添加任务与获取任务
void ThreadPool::addTask(Task* ptask) {
    if (ptask) {
        _taskQue.push(ptask);
    }
}

Task* ThreadPool::getTask() { return _taskQue.pop(); }

// 线程池交给工作线程执行的任务
void ThreadPool::doTask() {
    // 只要任务队列不为空，就应该让子线程（工作线程）获取任务并且执行任务
    // 只要线程池不退出，就一直让工作线程拿任务，并且执行任务
    while (!_isExit) {
        //子线程在getTask获取完任务之后，那么任务队列就会为空，那么
        //子线程（工作线程）会继续向下执行，去执行任务，也就是调用
        //process，而主线程在执行stop函数的时候，发现任务队列为空
        //那么主线程也会继续向下执行；如果出现主线程向下执行的速率
        //比较快，也就是子线程执行process的速率比较慢，那么主线程
        //很快会将标志位_isExit设置为true，那么当子线程执行完任务
        //process之后就不会再进入到while，那么主线程就可以将子线程
        //回收,那么整个程序就可以退出来;如果主线程执行的速率比较慢
        //也就是子线程执行的速率比较快，有可能子线程在执行完process
        //又进入到while循环，那么此时主线程再将标志位_isExit设置为
        //true就晚了，子线程会继续执行getTask进行获取任务，而任务
        //队列是空的，所以此时子线程会处于睡眠状态
        Task* ptask = getTask();
        if (ptask) {
            // 执行任务
            ptask->process();  // 此处会体现多态
        } else {
            cout << "ptask == nullptr" << endl;
        }
    }
}
