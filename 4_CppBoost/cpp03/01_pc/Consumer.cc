#include "Consumer.h"

#include <unistd.h>

#include <iostream>

#include "TaskQueue.h"

using std::cout;
using std::endl;

Consumer::Consumer() {}
Consumer::~Consumer() {}

void Consumer::consume(TaskQueue& taskQue) {
    int cnt = 20;
    while (cnt--) {
        int number = taskQue.pop();
        cout << "Consumer consume " << number << endl;
        sleep(1);
    }
}