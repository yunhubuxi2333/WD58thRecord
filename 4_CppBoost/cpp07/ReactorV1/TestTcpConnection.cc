#include <unistd.h>

#include <iostream>

#include "Acceptor.h"
#include "TcpConnection.h"

using std::cout;
using std::endl;

void test0() {
    Acceptor acceptor("127.0.0.1", 8888);
    acceptor.ready();  // 此时处于监听状态

    // 三次握手已经建立，可以创建一条tcp连接
    TcpConnection con(acceptor.accept());

    // 加调试，打印本端与对端的ip和端口号
    cout << con.toString() << "has connected" << endl;

    while (1) {
        cout << ">>recv msg from client:" << con.receive() << endl;
        con.send("hello baby\n");
    }
}

int main() {
    test0();
    return 0;
}
