#include "EventFd.h"

#include <poll.h>
#include <sys/eventfd.h>
#include <unistd.h>

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

EventFd::EventFd(EventFdCallback&& cb)
    : _evtfd(createEventFd()), _cb(std::move(cb)), _isStarted(false) {}

EventFd::~EventFd() { close(_evtfd); }

// 运行与停止
void EventFd::start() {
    struct pollfd pfd;
    pfd.fd = _evtfd;
    pfd.events = POLLIN;

    _isStarted = true;

    while (_isStarted) {
        int nready = poll(&pfd, 1, 5000);
        if (-1 == nready && errno == EINTR) {
            continue;
        } else if (-1 == nready) {
            cerr << "-1 == nready" << endl;
            return;
        } else if (0 == nready) {
            cout << ">>poll timeout!!!" << endl;
        } else {
            if (pfd.revents & POLLIN) {
                handldRead();
                if (_cb) {
                    _cb();  // 被唤醒后需要执行的任务
                }
            }
        }
    }
}

void EventFd::stop() { _isStarted = false; }

// 创建用于通信文件描述符
int EventFd::createEventFd() {
    int fd = eventfd(10, 0);
    if (fd < 0) {
        
        perror("createEventFd");
        return -1;
    }

    return fd;
}

// 封装read
void EventFd::handldRead(){

}

// 封装write
void EventFd::wakeup();
