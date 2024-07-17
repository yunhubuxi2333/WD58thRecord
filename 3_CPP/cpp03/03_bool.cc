#include <iostream>
using std::cout;
using std::endl;

void test0() {
    bool b1 = 1;
    bool b2 = 100;
    bool b3 = 3;
    bool b4 = -1;       // 非零值就是true
    bool b5 = 0;

    if (b5) {
        cout << "hello" << endl;
    }
    cout << b2 << endl;
    cout << b5 << endl;

    cout << "sizeof(bool):" << sizeof(b2) << endl;
}

int main() {
    test0();
    return 0;
}
