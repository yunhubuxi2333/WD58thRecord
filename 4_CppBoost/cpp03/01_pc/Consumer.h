#ifndef __CONSUMER_H__
#define __CONSUMER_H__

class TaskQueue;  // 前向声明
// 抽象类可以使用指针（由系统决定，64位一定是8个字节），但不能创建对象
class Consumer {
   public:
    Consumer();
    ~Consumer();

    void consume(TaskQueue& taskQue);
};

#endif