#include <iostream>
using std::cout;
using std::endl;

int num = 1;

namespace wd {
int num = 10;
void print() { cout << "wd:print()" << endl; }
}  // end of namespace wd

void test0() {
    cout << wd::num << endl;
}

int main() {
    test0();
    return 0;
}