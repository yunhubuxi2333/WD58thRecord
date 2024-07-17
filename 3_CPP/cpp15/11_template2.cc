#include <iostream>
using std::cout;
using std::endl;

template <class T1 = double, class T2 = double, class T3 = double>
T1 add(T2 x, T3 y) {
    return x + y;
}

void test0() {
    int a = 5;
    double b = 5.7;
    // 无法使用隐式实例化的场景需要显式实例化
    // 但是也尽量少地指定模板参数
    // 只指定必要的
    // 如果相应的模板参数有了默认值，就可以进行隐式实例化

    cout << add<double>(a, b) << endl;
    cout << add<double, int, int>(a, b) << endl;  // 指定类型优先级高于默认值

    cout << endl;
    cout << add(a, b) << endl;
}

int main(void) {
    test0();
    return 0;
}