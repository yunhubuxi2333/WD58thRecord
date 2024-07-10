#include <iostream>
using std::cout;
using std::endl;

class Base {
   public:
    Base(long x) : _base(x) {}
    virtual void display() const { cout << "Base::display()" << endl; }

   private:
    long _base;
};

class Derived : public Base {
   public:
    Derived(long base, long derived) : Base(base), _derived(derived) {}
    void display() const override { cout << "Derived::display()" << endl; }

   private:
    long _derived;
};

void test0() {
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    Derived d1(4, 8);
    Base* pb = &d1;

    pb->display();

    d1.display();
}

int main() {
    test0();
    return 0;
}