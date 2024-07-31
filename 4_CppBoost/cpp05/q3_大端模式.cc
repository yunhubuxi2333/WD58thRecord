#include <iostream>
using std::cout;
using std::endl;

void test0() {
    unsigned int a = 0x12345678;
    unsigned char* p = (unsigned char*)&a;
    if (*p == 0x12) {
        cout << "大端模式" << endl;
    } else if (*p == 0x78) {
        cout << "小端模式" << endl;
    }
}

int main() {
    test0();
    return 0;
}