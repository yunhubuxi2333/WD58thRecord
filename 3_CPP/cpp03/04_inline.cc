#include <iostream>
using std::cout;
using std::endl;

// 宏定义
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 内联函数
inline int max(int x, int y) { return x > y ? x : y; }

void test0() {
    // ( (20) > (10) ? (20) : (10) ) + 20
    int result = MAX(20, 10) + 20;  // result = 40

    // ( (10) > (20) ? (10) : (20) ) + 20
    int result2 = MAX(10, 20) + 20;  // result = 40

    cout << result << endl;
    cout << result2 << endl;
}

void test1() {
    int i = 4, j = 3;
    // 5,6
    int result = MAX(i++, j);  // 希望result = 4
    cout << result << endl;
    cout << i << endl;
}

void test2() {
    int i = 4, j = 3;
    // 4,5
    int result = max(i++, j);  // 希望result = 4
    cout << result << endl;
    cout << i << endl;
}

int main() {
    test0();
    test1();
    test2();
    return 0;
}
