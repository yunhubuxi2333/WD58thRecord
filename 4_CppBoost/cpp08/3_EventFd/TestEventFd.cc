#include <iostream>
#include "EventFd.h"


using std::cout;
using std::endl;
using std::bind;

class MyTask{
public:
    void process(){
        cout<<"MyTask"<<endl; 
    }
};

int main()
{
    MyTask task;
    EventFd efd(bind(&MyTask::process,&task));
    efd.start();

    thread th(bind(&EventFd::start,&efd));        //th是A线程，主线程是B线程

    efd.wakeup();





    efd.stop();
    th.join();


    return 0;
}

