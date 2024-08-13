#include "InetAddress.h"

#include <string.h>

InetAddress::InetAddress(const string& ip, unsigned short port) {
    ::bzero(&_addr, sizeof(struct sockaddr_in));
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(port);
    _addr.sin_addr.s_addr = inet_addr(ip.c_str());  // host->network
}

InetAddress::InetAddress(const struct sockaddr_in& addr) : _addr(addr) {}

InetAddress::~InetAddress() {}

string InetAddress::ip() const {
    // 从网络字节序转换为本机字节序
    // inet_ntoa是一个C语言函数，用于将网络字节序的32位无符号整数（通常是IPv4地址）转换成点分十进制表示的字符串。
    // 这个函数定义在<arpa/inet.h>头文件中。
    return string(inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port() const {
    // 从网络字节序转换为本机字节序
    // 网络字节序通常是大端模式，不同主机可能是大端或者小端模式
    // 这个函数保证了不同字节序的机器在网络上通信可以正确解析数据
    return ntohs(_addr.sin_port);
}

const struct sockaddr_in* InetAddress::getInetAddrPtr() const {
    //
    return &_addr;
}