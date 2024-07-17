#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Base {
   public:
    Base() : _pbase(new char[1]()), _base(0) {}
    Base(const char* pstr, long x)
        : _pbase(new char[strlen(pstr) + 1]()), _base(x) {
        strcpy(_pbase, pstr);
        cout << "Base()" << endl;
    }

    Base(const Base& rhs)
        : _pbase(new char[strlen(rhs._pbase) + 1]()), _base(rhs._base) {
        strcpy(_pbase, rhs._pbase);
        cout << "Base的拷贝构造函数" << endl;
    }

    Base& operator=(const Base& rhs) {
        if (this != &rhs) {
            delete[] _pbase;
            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase, rhs._pbase);
            _base = rhs._base;
        }

        cout << "Base的赋值运算符函数" << endl;
        return *this;
    }
    ~Base() {
        if (_pbase) {
            delete[] _pbase;
            _pbase = nullptr;
        }
    }

    void print() const {
        cout << "_pbase:" << _pbase << endl;
        cout << "_base: " << _base << endl;
    }

   private:
    char* _pbase;
    long _base;
};

class Derived : public Base {
   public:
    Derived(const char* pb, long base, long derived, const char* pd)
        : Base(pb, base),
          _derived(derived),
          _pderived(new char[strlen(pd) + 1]()) {
        strcpy(_pderived, pd);
    }

    Derived(const Derived& rhs)
        : Base(rhs),
          _derived(rhs._derived),
          _pderived(new char[strlen(rhs._pderived) + 1]()) {
        strcpy(_pderived, rhs._pderived);
        cout << "Derived的拷贝构造函数" << endl;
    }

    Derived& operator=(const Derived& rhs) {
        if (this != &rhs) {
            Base::operator=(rhs);
            delete[] _pderived;
            _derived = rhs._derived;
            _pderived = new char[strlen(rhs._pderived) + 1]();
            strcpy(_pderived, rhs._pderived);
        }

        cout << "Derive的赋值运算符函数" << endl;
        return *this;
    }

    ~Derived() {
        if (_pderived) {
            delete[] _pderived;
            _pderived = nullptr;
        }
    }

    void print() const {
        Base::print();
        cout << "_derived: " << _derived << endl;
        cout << "_pderived: " << _pderived << endl;
    }

   private:
    long _derived;
    char* _pderived;
};

void test0() {
    Base base("hello", 10);
    Derived d1("world", 4, 7, "shanghai");

    Derived d2("hello", 10, 8, "beijing");
    d2 = d1;
    d2.print();

    cout << endl;
    Derived d3 = d2;
    d3.print();
}

int main() {
    test0();
    return 0;
}