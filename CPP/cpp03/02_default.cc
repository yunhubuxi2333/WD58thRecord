#include <iostream>
using std::cout;
using std::endl;

void func(int x = 1, int y = 0) {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

void test0() {
    // 传入的参数优先级高于参数默认值
    func(1, 2);
    cout << endl;
    // 缺省调用
    func(100);
    cout << endl;
    func();
    cout << endl;
}

void func2(int a, int b, int c = 1);

void test1() {
    cout << endl;
    func2(2, 4, 5);
    cout << endl;
    func2(100, 200);
    cout << endl;
}

void func2(int a, int b, int c) { cout << a + b + c << endl; }

int main() {
    test0();
    test1();
    return 0;
}
