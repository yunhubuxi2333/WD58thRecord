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
    void show() const { cout << "B::show()" << endl; }
};

class C {
   public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
    void display() const { cout << "C::display()" << endl; }
};

class D : public A, public B, public C {
   public:
    D() { cout << "D()" << endl; }
    ~D() { cout << "~D()" << endl; }
};

void test0() {
    D d;
    d.print();
    d.show();
    d.display();
}

int main() {
    test0();
    return 0;
}