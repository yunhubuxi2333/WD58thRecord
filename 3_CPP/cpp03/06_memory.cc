#include <iostream>
using std::cout;
using std::endl;

int gNum = 100;

int add(int x, int y) { return x + y; }

void test0() {
    static int sNum = 20;

    int lNum = 1;
    int lNum2 = 10;
    cout << &lNum << endl;
    cout << &lNum2 << endl;

    int* p = new int(10);
    int* p2 = new int(20);

    cout << endl;
    cout << p2 << endl;
    cout << p << endl;

    cout << endl;
    // 在同一区中存放的变量先定义的在比较低的地址
    cout << &sNum << endl;
    cout << &gNum << endl;

    const char* pstr = "hello";
    cout << pstr << endl;
    printf("%p\n", pstr);
    cout << static_cast<const void*>(pstr) << endl;
    cout << static_cast<void*>(const_cast<char*>(pstr)) << endl;

    cout << endl;
    printf("%p\n", &test0);
}
int main() {
    test0();
    printf("%p\n", &main);
    return 0;
}
