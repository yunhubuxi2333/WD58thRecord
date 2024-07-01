#include <iostream>
using std::cout;
using std::endl;

extern int num;
namespace {
extern int val;
}

void test0() { 
    
    cout << ::val << endl; }

int main() {
    test0();
    return 0;
}