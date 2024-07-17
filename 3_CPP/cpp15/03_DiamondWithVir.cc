#include <iostream>
using std::cout;
using std::endl;

class B {
   public:
    virtual void f() { cout << "B::f()" << endl; }
    virtual void Bf() { cout << "B::Bf()" << endl; }

   private:
    int _ib;
    char _cb;
};

class B1 : virtual public B {
   public:
    virtual void f() { cout << "B1::f()" << endl; }
    virtual void f1() { cout << "B1::f1()" << endl; }
    virtual void Bf1() { cout << "B1::Bf1()" << endl; }

   private:
    int _ib1;
    char _cb1;
};

class B2 : virtual public B {
   public:
    virtual void f() { cout << "B2::f()" << endl; }
    virtual void f2() { cout << "B2::f2()" << endl; }
    virtual void Bf2() { cout << "B2::Bf2()" << endl; }

   private:
    int _ib2;
    char _cb2;
};

class D : public B1, public B2 {
   public:
    virtual void f() { cout << "D::f()" << endl; }
    virtual void f1() { cout << "D::f1()" << endl; }
    virtual void f2() { cout << "D::f2()" << endl; }
    virtual void Df() { cout << "D::Df()" << endl; }

   private:
    // double _d = 100;
    int _id;
    char _cd;
};