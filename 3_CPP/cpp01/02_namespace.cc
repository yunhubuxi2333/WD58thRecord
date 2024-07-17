#include <iostream>
using namespace std;

namespace wd {
int num = 10;
void print() { cout << "wd::print()" << endl; }
}  // namespace wd

namespace wd2 {
int num = 100;
void print() { cout << "wd2::print()" << endl; }
}  // namespace wd2

using namespace wd;
void test0() {
    cout << wd::num << endl;
    cout << wd::num << endl;
    wd::print();
    wd2::print();
}

int main() {
    test0();

    return 0;
}
