#include <functional>
#include <iostream>

using std::bind;
using std::cout;
using std::endl;
using std::function;

class Example {
   public:
    // 隐含在第一个参数的this,Example * const this
    int add(int x, int y) {
        cout << "int add(int,int)" << endl;
        return x + y;
    }
};

void test1() {
    Example ex;
    // 成员函数add的类型：int(Example *, int, int)
    // bind绑定之后的函数类型:int()无参
    // int(Example *)
    function<int(Example*)> f =
        bind(&Example::add, std::placeholders::_1, 10, 20);
    cout << "f(&ex) = " << f(&ex) << endl;
}

void test0() {
    Example ex;
    function<int()> func = bind(&Example::add, &ex, 10, 20);
    cout << "func() = " << func() << endl;

    cout << endl;
    function<int()> func2 = bind(&Example::add, &ex, 30, 40);
    cout << "func2() = " << func2() << endl;
}

int main() {
    test0();
    return 0;
}