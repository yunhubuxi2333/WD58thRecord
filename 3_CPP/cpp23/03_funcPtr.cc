#include <iostream>
using std::cout;
using std::endl;

int func() {
    cout << "int func()" << endl;
    return 10;
}

int func2() {
    cout << "int func2()" << endl;
    return 20;
}

int func3(int x, int y) {
    cout << "int func3(int,int)" << endl;
    return x + y;
}
void test0() {
    typedef int (*pFunc)();  // ok,C中语法
    // typedef int (*)() pFunc;     //error,语法是有问题的
    // using pFunc = int (*)();  // C++语法
    // typedef A B
    // typedef int B;
    // int (*pFunc)();

    // 延迟func函数的调用
    pFunc f = &func;  // 回调函数的注册
    // pFunc = func2;

    cout << "f() = " << f() << endl;  // 回调函数的执行

    pFunc f2 = func2;
    cout << "f2() = " << f2() << endl;

    // 函数指针只能指向固定类型的函数
    // pFunc f3 = func3;  // error,func3为(int,int)函数
}

int main() {
    test0();
    return 0;
}