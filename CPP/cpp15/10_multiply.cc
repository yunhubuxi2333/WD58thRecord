#include <iostream>

using std::cout;
using std::endl;

#define PI 3.14

template <class T = int, int kBase = 10>
T multiply(T x, T y) {
    return x * y * kBase;
}

void test0() {
    // 指定的优先级最高
    cout << multiply<double, 20>(1.2, 1.2) << endl;
    // 推导的优先级高于默认值
    cout << multiply(1.2, 1.2) << endl;
    cout << multiply(PI, PI) << endl;
}

int main() {
    test0();
    return 0;
}