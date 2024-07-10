#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
    void print() const { cout << "A::print()" << endl; }
};

class B {
   public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
    void print() const { cout << "B::print()" << endl; }
};

class C {
   public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
    void print() const { cout << "C::print()" << endl; }
};

class D : public A, public B, public C {
   public:
    D() { cout << "D()" << endl; }
    ~D() { cout << "~D()" << endl; }
    void print() const { cout << "D::print()" << endl; }
};

void test0() {
    D d;
    d.print();
    d.A::print();
    d.B::print();
    d.C::print();
}

int main() {
    test0();
    return 0;
}