#include <iostream>
#include <thread>

#include "Consumer.h"
#include "Producer.h"
#include "TaskQueue.h"

using std::cout;
using std::endl;
using std::thread;

int main(int argc, char* argv[]) {
    Producer pr;
    Consumer co;
    TaskQueue taskQue(10);

    // 线程入口函数使用的是值传递
    thread pro(&Producer::produce, &pr, std::ref(taskQue));
    thread con(&Consumer::consume, &co, std::ref(taskQue));

    pro.join();
    con.join();

    return 0;
}