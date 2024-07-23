#include <functional>
#include <iostream>
#include <string>

using std::bind;
using std::cout;
using std::endl;
using std::function;
using std::string;

int add(int x, int y) {
    cout << "int add(int,int)" << endl;
    return x + y;
}

void test0() {
    using namespace std::placeholders;
    function<int(int, int)> f = bind(add, _1, _2);
    cout << "f(10, 20) = " << f(10, 20) << endl;

    cout << endl;
    function<int(int)> f2 = bind(add, _1, 20);
    cout << "f2(90) = " << f2(90) << endl;

    cout << endl;
    function<int(const string&, int)> f3 =
        bind(add, 10, _2);  // 形参，使用实参的第二个，第一个是什么无所谓
    cout << "f3(\"hello\",100) = " << f3("hello", 100) << endl;  // 实参
}

int main() {
    test0();
    return 0;
}