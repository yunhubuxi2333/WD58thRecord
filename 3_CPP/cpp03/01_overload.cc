#include <iostream>
using std::cout;
using std::endl;

int add(int x, int y) { return x + y; }

int add(int x, int y, int z = 0) { return x + y + z; }

double add(double x, double y) { return x + y; }

// 在C++代码中如果想要嵌入C的代码
// 可以使用extern "C"
// 大括号中的内容会按照C编译器的方式进行处理
// extern "C" {

float add(int x, float y) { return x + y; }

float add(float x, int y) { return x + y; }
// }
void test0() {
    double a = 1.5, b = 3.8;
    cout << add(a, b) << endl;

    int c = 3, d = 4, e = 5;
    cout << add(c, d, e) << endl;

    // 如果函数参数有默认值
    // 在进行函数重载时要注意避免冲突
    // cout << add(c, d) << endl;

    float p = 1.4;
    int q = 4;
    cout << add(p, q) << endl;
    cout << add(p, q) << endl;
}

int main() {
    test0();
    return 0;
}
