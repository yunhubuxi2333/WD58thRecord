#include <math.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Base {
   public:
    virtual void print() { cout << "Base::print()" << endl; }
    virtual void display() { cout << "Base::display()" << endl; }
    virtual void show() { cout << "Base::show()" << endl; }

   private:
    long _base = 10;
};

class Derived : public Base {
   public:
    virtual void print() override { cout << "Derived::print()" << endl; }
    virtual void display() override { cout << "Derived::display()" << endl; }
    virtual void show() override { cout << "Derived::show()" << endl; }

    virtual void func() { cout << "Derived::func()" << endl; }

   private:
    long _derived = 100;
};

void test0() {
    Derived d;
    long* pDerived = reinterpret_cast<long*>(&d);
    cout << pDerived[0] << endl;
    cout << pDerived[1] << endl;
    cout << pDerived[2] << endl;

    cout << endl;
    long* pVtable = reinterpret_cast<long*>(pDerived[0]);
    cout << pVtable[0] << endl;
    cout << pVtable[1] << endl;
    cout << pVtable[2] << endl;

#if 1
    cout << endl;
    static int num = 0;
    const char* pstr = "hello";
    cout << &num << endl;
    cout << pVtable << endl;
    printf("%p\n", pstr);
    printf("%p\n", &test0);
#endif

    cout << endl;
    typedef void (*Function)();
    Function f = (Function)(pVtable[0]);
    f();
    f = (Function)(pVtable[1]);
    f();
    f = (Function)(pVtable[2]);
    f();
    f = (Function)(pVtable[3]);
    f();

    cout << endl;
}

int main() {
    test0();
    return 0;
}