#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t capa)
    : _capacity(capa), _que(), _mutex(), _notEmpty(), _notFull(), _flag(true) {}

TaskQueue::~TaskQueue() {}

// 添加任务与获取任务
void TaskQueue::push(ElemType ptask) {
    unique_lock<mutex> ul(_mutex);

    while (isFull()) {
        // 上半部：先解锁再睡眠
        // 下半部：被唤醒之后需要上锁再返回
        _notFull.wait(ul);
    }
    // 如果不是满的，就可以生产数据，就可以唤醒消费者线程
    _que.push(ptask);
    _notEmpty.notify_one();
    // 解锁
    // _mutex.unlock();
}

ElemType TaskQueue::pop() {
    // 上锁
    unique_lock<mutex> ul(_mutex);
    // 判断任务队列是不是空的
    while (isEmpty() && _flag) {
        // 如果是空的，睡眠
        _notEmpty.wait(ul);
    }
    if (_flag) {
        // 如果不是空的，就可以生产数据，就可以唤醒生产者线程
        ElemType tmp = _que.front();
        _que.pop();
        _notFull.notify_one();

        // 解锁
        return tmp;
    } else {
        return nullptr;
    }
}

// 判空与判满
bool TaskQueue::isEmpty() const { return _que.size() == 0; }
bool TaskQueue::isFull() const { return _capacity == _que.size(); }

void TaskQueue::wakeup() {
    _flag = false;
    _notEmpty.notify_all();
}