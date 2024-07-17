#include <iostream>
using std::cout;
using std::endl;

class Base {
   public:
    Base(long x) : _base(x) { cout << "Base()" << endl; }

    virtual void print() { cout << "Base::print()" << endl; }

    int getBase() { return _base; }

    //    private:
    long _base;
};

class Derived : public Base {
   public:
    Derived(long base, long derived) : Base(base), _derived(derived) {
        cout << "Derived()" << endl;
    }
    long _derived;
};

void test0() {
    Base base(10);
    Derived d1(6, 7);

    // 底层是base对象调用了Base类的赋值运算符函数
    // base.operator=(d1);
    // 形参const Base &rhs = d1
    base = d1;
    // d1 = base;      //error

    Base* pbase = &d1;
    cout << pbase->_base << endl;

    Base& ref = d1;
    cout << ref._base << endl;
}

void test1() {
    Base base(6);
    Derived d1(7, 9);

    // 接下来向下转型不合理
    // Base* pbase = &base;

    // 合理
    Base* pbase = &d1;
    cout << pbase->_base << endl;

    // 此处pbase本身就是指向派生类对象
    // 向下转型是合理的
    // 但是不能直接向下转型

    // 如果是合理的向下转型，会返回一个合法的Derived*
    // 如果是不合理的向下转型，会返回空指针
    Derived* pd = dynamic_cast<Derived*>(pbase);
    if (pd) {
        cout << "转换成功" << endl;
        cout << pd->_derived << endl;
    } else {
        cout << "转换失败" << endl;
    }
}

int main() {
    test1();
    return 0;
}