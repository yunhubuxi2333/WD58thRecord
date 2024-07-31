#ifndef _EVENTLOOP_H__
#define _EVENTLOOP_H__
#include <sys/epoll.h>
#include <memory>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::shared_ptr;

class TcpConnection;
class Acceptor;//前向声明

class EventLoop
{
    using TcpConnectionPtr = shared_ptr<TcpConnection>;
public:
    EventLoop(Acceptor& _acceptor) {}
    ~EventLoop() {}

    //是否在循环
    void loop();
    void unloop();

    //封装epoll_wait
    void waitEpollFd();

    //处理新的连接
    void handleNewConnection();

    //处理老的连接上的数据
private:
    int _epfd;
    vector<struct epoll_event> _evtList;
    bool isLooping;
    Acceptor & _acceptor;

};
#endif
