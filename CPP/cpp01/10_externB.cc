#include <iostream>
using std::cout;
using std::endl;

// 外部引入声明
extern int val;
extern void display();

namespace wd {
extern int val;
extern void display();
}  // namespace wd

void test0() {
    cout << val << endl;
    display();

    // 当externA中全局位置定义了与命名空间作用域中
    // 同名的实体
    // 在externB中同时进行外部引入
    // 那么想要访问命名空间内容时
    // ::和using xxx::xxx可以，using namespace xxx会造成冲突

    using wd::display;
    using wd::val;

    cout << val << endl;
    display();
}
int main() {
    test0();

    return 0;
}