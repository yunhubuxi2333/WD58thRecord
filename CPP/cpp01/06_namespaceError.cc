#include <iostream>
using std::cout;
using std::endl;

int num = 9;

namespace wd {

int num = 10;

void print() { cout << "wd::print()" << endl; }
}  // namespace wd

namespace wd2 {
int num = 100;

void print() { cout << "wd::print()" << endl; }
}  // namespace wd2

void test0() {
    using wd::num;
    using wd::print;      // 只写函数名
    using wd2::print;     // 只写函数名
    cout << num << endl;  // 对全局变量起到屏蔽效果
    // print();    //发生冲突
    wd::print();
    wd2::print();
}

int main(void) {
    test0();
    return 0;
}