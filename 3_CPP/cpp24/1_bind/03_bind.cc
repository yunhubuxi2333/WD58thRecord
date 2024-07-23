#include <functional>
#include <iostream>

using std::bind;
using std::cout;
using std::endl;
using std::function;

// 在C语言中，函数名就是函数的入口地址
// 在C语言中，数组名也是数组的入口地址
int add(int x, int y) {
    cout << "int add(int,int)" << endl;
    return x + y;
}

int func(int x, int y) { return 1; }

int multiply(int x, int y, int z) {
    cout << "int multiply(int,int,int)" << endl;
    return x * y * z;
}

class Example {
   public:
    // 隐含在第一个参数的this, Example * const this
    int add(int x, int y) {
        cout << "int Example::add(int,int)" << endl;
        return x + y;
    }
};

void test1() {
    typedef int (*pFunc)(int, int);
    pFunc f = add;
    f = func;
}

void test0() {
    // 函数的类型：函数的返回类型 + 函数的参数列表
    // add的函数类型：int(int,int)
    // bind绑定之后的函数类型:int()无参
    function<int()> f = bind(add, 1, 2);
    cout << "f() = " << f() << endl;

    cout << endl;
    // multiply的函数类型：int(int,int,int)
    // bind绑定之后的函数类型:int()无参
    function<int()> f2 = bind(&multiply, 3, 4, 5);
    cout << "f2() = " << f2() << endl;

    cout << endl;
    Example ex;
    // 成员函数add的类型：int(Example *, int, int)
    // bind绑定之后的函数类型:int()无参
    function<int()> f3 = bind(&Example::add, &ex, 10, 20);
    cout << "f3() = " << f3() << endl;

    cout << endl;
    // 占位符
    using namespace std::placeholders;
    function<int(int)> f4 = bind(add, _1, 1001);
    cout << "f4(999) = " << f4(999) << endl;

    cout << endl;
    // 占位符
    // function可以存放函数类型，将function称为函数的容器
    function<int(int, int)> f5 = bind(add, _1, _2);
    cout << "f5(111,222) = " << f5(111, 222) << endl;
}

int main() {
    test0();
    return 0;
}