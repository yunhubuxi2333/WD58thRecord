#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 函数模板
template <class T>
T add(T t1, T t2) {
    cout << "模板一" << endl;
    return t1 + t2;
}

template <class T1, class T2>
T1 add(T1 t1, T2 t2) {
    cout << "模板二" << endl;
    return t1 + t2;
}

void test0() {
    int i1 = 3, i2 = 4;
    double d1 = 1.6, d2 = 2.8;

    // cout << add(i1, d2) << endl;  // 模板二，因为模板一无法使用
    // cout << add(d1, i2) << endl;  // 隐式实例化，并且不损失精度

    // // 模板一，使用了更少的模板参数
    // cout << add(i1, i2) << endl;

    // cout << endl;
    // // 模板二，模板一不允许指定两个类型参数
    // cout << add<int, double>(i1, d2) << endl;

    // // 第一个参数被指定为int,其本身也是int
    // // 第二个参数没有被指定类型，推导出double
    // // 使用模板二不需要对参数进行任何的类型转换，编译器优先选择
    // cout << add<int>(i1, d2) << endl;

    cout << add<double>(i1, d2) << endl;
}

int main() {
    test0();
    return 0;
}