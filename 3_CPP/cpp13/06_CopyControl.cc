#include <iostream>
using std::cout;
using std::endl;

class Base {
   public:
    Base(long x) : _base(x) {}

    Base(const Base& rhs) : _base(rhs._base) {
        cout << "Base的拷贝构造函数" << endl;
    }

    Base& operator=(const Base& rhs) {
        cout << "Base的赋值运算符函数" << endl;
        _base = rhs._base;
        return *this;
    }

    void print() const { cout << "_base:" << _base << endl; }

    long _base;
};

class Derived : public Base {
   public:
    Derived(long base, long derived) : Base(base), _derived(derived) {}

    Derived(const Derived& rhs) : Base(rhs), _derived(rhs._derived) {
        cout << "Derived的拷贝构造函数" << endl;
    }

    Derived& operator=(const Derived& rhs) {
        Base::operator=(rhs);  // 显式调用Base类的赋值运算符函数
        _derived = rhs._derived;
        cout << "Derived的赋值运算符函数" << endl;
        return *this;
    }

    void print() const {
        Base::print();
        cout << "_derived:" << _derived << endl;
    }

    long _derived;
};

void test0() {
    Base base(10);
    Derived d1(4, 6);

    // 底层是base对象调用了Base类的赋值运算符函数
    // base.operator=(d1);
    base = d1;

    cout << base._base << endl;
}

void test1() {
    Derived d1(6, 9);

    Derived d2(5, 7);

    d1 = d2;
    d1.print();

    cout << endl;
    Derived d3 = d2;
    d3.print();
}
int main() {
    test1();

    return 0;
}