#include "EventLoop.h"
#include <sys/epoll.h>
#include <cstddef>
#include <iostream>
#include <new>
#include "Acceptor.h"

using std::cout;
using std::endl;
using std::cerr;

class EventLoop::EventLoop(Acceptor &acceptor){
    int listenfd = _acceptor.fd();

    EventLoop::~EventLoop(){
        close(_epfd);
    }


    void EventLoop::waitEpollFd(){
        int nready =0; 
        do{
            nready = ::epoll_wait(_epfd,),&_evtList[0],_evtList.size(),3000);
        }while(-1 = nready && errno == EINTR);

        if(-1 == nready){
            cerr<<"-1 == nready"<<endl;
        }else if(0 == nready){
            cout<<">>epoll_wait timeout!!!"<<endl;
        }else{
            //为了防止文件描述符的数目超过1024，我们可以手动扩容
            if(nready == _evtList.size()){
                //insert/push_back可以自动扩容
                //reserve/resize
                _evtList.resize(2*nready);
            }
            for(int idx = 0;idx < nready;++idx){
                int fd= _evtList[idx].data.fd;
                int listenfd = _acceptor.fd();

                if(fd == listenfd){
                    std::set_new_handler
                }
            }
        }
    }

    //处理新的连接
    void EventLoop::handleNewConnection(){
        //如果connfd是正常的，就表明三次握手完全成功
        int connfd = _acceptor.accept();
        if(connfd < 0){
            perror("handleNewConnection");
            return;
        }

        //将文件描述符connfd放在红黑树上进行监听
        addEpollReadFd(connfd);
        //三次握手建立成功，就可以创建出TcpConnection连接

        TcpConnection * con(new TcpConnection(connfd));
        
        //存储文件描述符connfd与连接TcpConnection的键值对
        //conns.insert({connfd,con});
        _conns[connfd] = con;
    }
    //处理老的连接上的数据
    void EventLoop::handleMessage(int fd){
        auto it = _conns.find(fd);
        if(it != _conns.end()){
            //接收客户端的数据
           string msg= it->second->recvive();
           cout<<">>recv msg from client:"<<msg<<endl;
           
           //做业务逻辑的处理

           //业务逻辑处理完毕之后，需要将数据msg发给客户

        }
    }
    //封装epoll_create函数
    

    void EventLoop::addEpollReadFd(int fd){
        struct epoll_event evt;

        int ret = ::epoll_ctl(_epfd,EPOLL_CTL_ADD,fd,&evt);
        if(ret < 0){
            perror("addEpollReadFd");
            return;
        }
    }
};








int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

