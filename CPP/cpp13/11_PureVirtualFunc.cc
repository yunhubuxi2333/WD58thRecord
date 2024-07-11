#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    virtual void print() = 0;
    virtual void display() = 0;
};

class B : public A {
   public:
    virtual void print() override { cout << "B::print()" << endl; }
    virtual void display() override { cout << "C::display()" << endl; }
};

class C : public B {
   public:
    virtual void display() override { cout << "C::display()" << endl; }
};

void test1() {
    C c1;
    A* pa = &c1;
    pa->print();
    pa->display();
}

void test0() {
    // A a1;
    B b1;
    A* pa = &b1;
    pa->print();
    pa->display();

    A& ref = b1;
    ref.print();
    ref.display();
}

int main() {
    test0();

    return 0;
}