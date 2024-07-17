#include <iostream>
using std::cout;
using std::endl;

void printType() { cout << endl; }

// 重新定义一个可变参数模板，至少得有一个参数
template <class T, class... Args>
void printType(T x, Args... args) {
    cout << typeid(x).name() << " ";
    printType(args...);
}

void test0() { printType(1, "hello", 3.6, true, 1000, 'a'); }

int main() {
    test0();
    return 0;
}