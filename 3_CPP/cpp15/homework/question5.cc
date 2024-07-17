#include <algorithm>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

class A {
   public:
    virtual void a() { cout << "A::a()" << endl; }
    void b() { cout << "A::b()" << endl; }
    virtual void c() { cout << "A::c()" << endl; }
    void e() { cout << "A::e()" << endl; }
};

class B {
   public:
    virtual void a() { cout << "B::a()" << endl; }
    void c() { cout << "B::c()" << endl; }
    void d() { cout << "B::d()" << endl; }
    virtual void f() { cout << "B::f()" << endl; }
};

class C : public A, public B {
   public:
    virtual void a() { cout << "C::a()" << endl; }
    virtual void b() { cout << "C::b()" << endl; }
    void c() { cout << "C::c()" << endl; }
    void d() { cout << "C::d()" << endl; }
};

void test0() {
    C c;
    c.a();  // C::a()
    c.b();  // C::b()
    c.c();  // C::c()
    c.d();  // C::d()     
    c.e();  // A::e()
    c.f();  // B::f()

    cout << endl;
    A* pa = &c;
    pa->a();  // C::a()
    pa->b();  // A::b()
    pa->c();  // C::c()
    // pa->d();  // error
    pa->e();  // A::e()
    // pa->f();  // error

    cout << endl;
    B* pb = &c;
    pb->a();  // C::a()
    // pb->b();  // error
    pb->c();  // B::c()
    pb->d();  // B::d()
    // pb->e();  // error
    pb->f();  // B::f()

    cout << endl;
    C* pc = &c;
    pc->a();  // C::a()
    pc->b();  // C::b()
    pc->c();  // C::c()
    pc->d();  // C::d()
    pc->e();  // A::e()
    pc->f();  // B::f()
}

int main() {
    test0();
    return 0;
}