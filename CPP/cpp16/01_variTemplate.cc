#include <iostream>
using std::cout;
using std::endl;

void print() {
    cout << endl;
    cout << "递归出口一" << endl;
}

// void print(int x) {
//     cout << endl;
//     cout << "递归出口二" << endl;
// }

template <class T, class... Args>
void print(T x, Args... args) {
    cout << x << " ";
    print(args...);  // 省略号在包的右边表示解包
}

void test0() { print(1, "hello", 3.4, true, false, 2000); }

int main() {
    test0();
    return 0;
}