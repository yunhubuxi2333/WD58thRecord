#include "Producer.h"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>

#include "TaskQueue.h"

using std::cout;
using std::endl;

Producer::Producer() {}
Producer::~Producer() {}

void Producer::produce(TaskQueue& taskQue) {
    ::srand(::clock());  //  种随机种子
    // 匿名命名空间,表明是C语言的函数
    int cnt = 20;
    while (cnt--) {
        int number = ::rand() % 100;  // 产生随机数
        taskQue.push(number);
        cout << "Producer produce = " << number << endl;
        sleep(1);
    }
}