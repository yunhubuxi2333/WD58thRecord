#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 10;
void print() { cout << "wd::print()" << endl; }
}  // namespace wd

namespace wd2 {
int num = 100;
void print() { cout << "wd2::print()" << endl; }
}  // namespace wd2

void test0() {
    using namespace wd;
    cout << num << endl;
    print();
}

void test1() {
    using namespace wd2;
    cout << num << endl;
    print();
}

void test2() {
    cout << wd::num << endl;
    cout << wd2::num << endl;
}
int main() {
    test0();
    test1();
    test2();

    return 0;
}
