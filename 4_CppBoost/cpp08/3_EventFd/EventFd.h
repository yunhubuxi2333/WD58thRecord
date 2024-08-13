#ifndef __EVENTFD_H__
#define __EVENTFD_H__

#include <functional>

using std::function;

class EventFd {
    using EventFdCallback = function<void()>;

   public:
    EventFd::EventFd(EventFdCallback&& cb);
    ~EventFd();

    // 运行与停止
    void start();
    void stop();

    // 创建用于通信文件描述符
    int createEventFd();

    // 封装read
    void handldRead();

    // 封装write
    void wakeup();

   private:
    int _evtfd;           // 用于通信的文件描述符
    EventFdCallback _cb;  // 被唤醒后需要执行的任务
    bool _isStarted;      // 标识运行与否
};

#endif
