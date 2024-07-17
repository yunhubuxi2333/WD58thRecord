#include <iostream>

using std::cout;
using std::endl;

class A {
   public:
    virtual void display() { cout << "A::display()" << endl; }
    virtual void show() { cout << "A::show()" << endl; }
    virtual void print() { cout << "A::print()" << endl; }

   private:
    long a;
};

class B : public A {
   public:
    virtual void print() override { cout << "1  B::print()" << endl; }
    virtual void show() override { cout << "2  B::show()" << endl; }
    virtual void display() override { cout << "3  B::display()" << endl; }

   private:
    long b;
};

void test0() {
    B b;
    long* pb = reinterpret_cast<long*>(&b);

    cout << pb[0] << endl;
    cout << pb[1] << endl;
    cout << pb[2] << endl;

    cout << endl;
    long* pVtable = reinterpret_cast<long*>(pb[0]);
    cout << pVtable[0] << endl;
    cout << pVtable[1] << endl;
    cout << pVtable[2] << endl;

    cout << endl;
    typedef void (*Function)();
    Function f = (Function)(pVtable[0]);
    f();
    f = (Function)(pVtable[1]);
    f();
    f = (Function)(pVtable[2]);
    f();
}

int main() {
    test0();
    return 0;
}