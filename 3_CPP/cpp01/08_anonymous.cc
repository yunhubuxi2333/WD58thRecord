#include <iostream>
using std::cout;
using std::endl;

int num = 100;

// 匿名空间
namespace {
int num = 10;
void print() { cout << "wd::print()" << endl; }
}  // namespace
void test0() { cout << ::num << endl; }
int main() {
    test0();

    return 0;
}