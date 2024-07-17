#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    virtual void a() { cout << "A::a()" << endl; }
    virtual void b() { cout << "A::b()" << endl; }
    virtual void c() { cout << "A::c()" << endl; }
};

class B {
   public:
    virtual void a() { cout << "B::a()" << endl; }
    virtual void b() { cout << "B::b()" << endl; }
    void c() { cout << "B::c()" << endl; }
    void d() { cout << "B::d()" << endl; }
};

class C : public A, public B {
   public:
    virtual void a() { cout << "C::a()" << endl; }
    void c() { cout << "C::c()" << endl; }
    void d() { cout << "C::d()" << endl; }
};

class D : public C {
   public:
    void c() { cout << "D::c()" << endl; }
};

void test0() {
    C c;
    c.a();  // C::a()   理解为隐藏，没有通过虚函数表
    /* c.b(); //需要通过基类子对象调用，有冲突 */
    c.c();  // C::c() 理解为隐藏，没有通过虚函数表
    c.d();  // C::d() 隐藏

    cout << endl;
    A* pa = &c;
    pa->a();  // C::a() 动态多态
    pa->b();  // A::b() 没有覆盖，不会触发动态多态，会通过虚函数表
    pa->c();  // C::c() 动态多态
    /* pa->d();//A类没有定义d()，无法调用 */

    cout << endl;
    B* pb = &c;
    pb->a();  // C::a() 动态多态
    pb->b();  // B::b() 没有覆盖，不会触发动态多态，会通过虚函数表
    pb->c();  // B::c() 对于B类c函数是普通成员函数,不会通过虚函数表
    pb->d();  // B::d() 同上

    cout << endl;
    C* pc = &c;
    pc->a();  // C::a() 通过虚函数表
    /* pc->b();//成员名访问冲突二义性 */
    pc->c();  // C::c() c函数对于C类是虚函数，通过虚函数表调用
    pc->d();  // C::d() 不是虚函数

    cout << endl;
    D d;
    C* c1 = &d;
    c1->c();
}

int main(void) {
    test0();
    return 0;
}