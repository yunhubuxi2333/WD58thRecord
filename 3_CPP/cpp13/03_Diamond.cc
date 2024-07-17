#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    void print() const { cout << "A::print()" << endl; }
    double _a;
};

class B : public A {
   public:
    double _b;
};

class C : public A {
   public:
    double _c;
};

class D : public B, public C {
   public:
    double _d;
    void print() const { cout << "D::print()" << endl; }
};

void test0() {
    cout << sizeof(D) << endl;
    D d1;
    d1.print();
    d1.B::print();
    d1.C::print();
}

int main() {
    test0();
    return 0;
}