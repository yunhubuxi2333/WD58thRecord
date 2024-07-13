#include <iostream>
using std::cout;
using std::endl;

// 基本递归结束条件
template <typename T>
T add(T t) {
    return t;
}

// 可变参数模板
template <typename T, typename... Args>
T add(T first, Args... args) {
    return first + add(args...);
}

void test0() {
    int sum_int = add(1, 2, 3, 4, 5);
    double sum_double = add(1.1, 2.2, 3.3, 4.4, 5.5);
    cout << "sum_int = " << sum_int << endl;
    cout << "sum_double = " << sum_double << endl;
}

int main() {
    test0();
    return 0;
}