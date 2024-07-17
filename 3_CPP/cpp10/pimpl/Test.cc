#include <iostream>

#include "Line.hh"
using std::cout;
using std::endl;

void test0() {
    Line ll(1, 2, 3, 4);
    ll.printLine();
}

int main(void) {
    test0();
    return 0;
}