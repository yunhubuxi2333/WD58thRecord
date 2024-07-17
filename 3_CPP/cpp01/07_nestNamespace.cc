#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 10;
void display() { cout << "wd::display()" << endl; }
namespace cpp {
int num = 100;
void display() { cout << "wd::cpp::display()" << endl; }
}  // namespace cpp
}  // namespace wd

void test0() {
    // 1.::作用域限定符
    cout << wd::num << endl;
    wd::display();
    cout << wd::cpp::num << endl;
    wd::cpp::display();
}

void test1() {
    // 2.using namespace using 编译指令
    using namespace wd::cpp;
    cout << num << endl;
    display();
}

void test2() {
    // 3.需要什么就用什么   using 声明机制
    using wd::cpp::num;
    using wd::cpp::display;
    cout << num << endl;
    display();
}
int main() {
    test0();
    test1();
    test2();

    return 0;
}