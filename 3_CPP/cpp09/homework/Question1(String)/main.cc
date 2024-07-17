#include <iostream>

#include "String.hpp"

using std::cout;
using std::endl;

void test0() {
    String s1;
    cout << "s1 = " << s1 << endl;

    String s2 = "hello";
    cout << "s2 = " << s2 << endl;

    s2 = "world";
    cout << "s2 = " << s2 << endl;
}

void test1() {
    String s1("hello");
    String s2("world");

    s1 += s2;
    cout << "s1=" << s2 << endl;
}

int main() {
    // test0();
    test1();

    return 0;
}