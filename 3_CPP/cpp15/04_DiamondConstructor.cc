#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    A(double a) : _a(a) { cout << "A(double)" << endl; }
    ~A() { cout << "~A()" << endl; }
};