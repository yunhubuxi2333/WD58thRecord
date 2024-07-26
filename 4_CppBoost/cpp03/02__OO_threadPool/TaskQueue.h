#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <condition_variable>
#include <mutex>
#include <queue>

using std::condition_variable;
using std::mutex;
using std::queue;
using std::unique_lock;

class Task;  // 前向声明
class TaskQueue {
    using ElemType = Task*;

   public:
    TaskQueue(size_t capa);
    ~TaskQueue();

    // 添加任务与获取任务
    void push(ElemType ptask);
    int pop();

    // 判空与判满
    bool isEmpty() const;
    bool isFull() const;

   private:
    size_t _capacity;              // 任务队列的大小
    queue<ElemType> _que;               // 存放数据的数据结构
    mutex _mutex;                  // 互斥锁
    condition_variable _notEmpty;  // 非空条件变量
    condition_variable _notFull;   // 非满条件变量
};

#endif