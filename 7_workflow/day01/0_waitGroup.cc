#include <signal.h>
#include <workflow/WFFacilities.h>

#include <iostream>

using std::cout;
// static 全局变量or函数 只在本文件里面生效
static WFFacilities::WaitGroup waitGroup(1);
// static 局部变量：这是静态变量
// static 类成员 和类相关的成员

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

int main() {
    signal(SIGINT, sighandler);
    waitGroup.wait();
    cout << "finished!\n";
}
