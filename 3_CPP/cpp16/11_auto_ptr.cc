#include <iostream>
#include <memory>
using std::auto_ptr;
using std::cout;
using std::endl;

void test0() {
    // int* p = new int(10);
    // auto_ptr<int> ap(p);
    // 智能指针通常在构造函数参数初始化时直接使用new表达式
    auto_ptr<int> ap(new int(20));
    cout << *ap << endl;
}

void test1() {
    // 智能指针通常在构造函数参数初始化时直接使用new表达式
    auto_ptr<int> ap(new int(20));
    cout << *ap << endl;

    cout << endl;
    auto_ptr<int> ap2(ap);
    // 虽然调用了拷贝构造，但是底层的实现是移交管理权的操作
    // ap失去了对之前的资源空间的管理权
    // cout << *ap << endl;
    cout << *ap2 << endl;
}

int main() {
    test1();
    return 0;
}