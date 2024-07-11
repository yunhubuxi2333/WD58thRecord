#include <iostream>
using std::cout;
using std::endl;

class Grandpa {
   public:
    Grandpa() { cout << "Grandpa()" << endl; }
    ~Grandpa() { cout << "~Grandpa()" << endl; }

    virtual void func1() { cout << "Grandpa::func1()" << endl; }
    virtual void func2() { cout << "Grandpa::func2()" << endl; }
};

class Parent : public Grandpa {
   public:
    Parent() {
        cout << "Parent()" << endl;
        func1();
    }

    ~Parent() {
        cout << "~Parent()" << endl;
        func2();
    }
    virtual void func1() override { cout << "Parent::func1()" << endl; }
    virtual void func2() override { cout << "Parent::func2()" << endl; }
};

class Son : public Parent {
   public:
    Son() { cout << "Son()" << endl; }
    ~Son() { cout << "~Son()" << endl; }
    virtual void func1() override { cout << "Son::func1()" << endl; }
    virtual void func2() override { cout << "Son::func2()" << endl; }
};

void test0() { Son ss; }

int main(void) {
    test0();
    return 0;
}