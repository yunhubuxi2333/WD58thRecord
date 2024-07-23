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
    // int data() {}
    int data = 100;  // C++11可以直接将数据成员初始化
    // int data;
};

void test0() {
    Example ex;
    // 成员函数add的类型：int(Example *, int, int)
    // bind绑定之后的函数类型:int()无参
    function<int()> f = bind(&Example::add, &ex, 10, 20);
    cout << "f() = " << f() << endl;

    cout << endl;
    function<int()> f2 = bind(&Example::data, &ex);
    cout << "f2() = " << f2() << endl;
}  // y/d + 目标行号 + G

int main() {
    test0();
    return 0;
}