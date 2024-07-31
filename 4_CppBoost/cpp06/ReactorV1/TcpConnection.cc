#include "TcpConnection.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

explicit TcpConnection(int fd){
    
}
~TcpConnection();
void send(const string& msg);
string receive();


string toString();

private:
// 获取本端地址与对端的地址
InetAddress getLocalAddr();
InetAddress getPeerAddr();
