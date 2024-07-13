#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class String {
   public:
    String() : _pstr(new char[1]()) { cout << "String()" << endl; }

    String(const char* pstr) : _pstr(new char[strlen(pstr) + 1]()) {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String& rhs) : _pstr(new char[strlen(rhs._pstr) + 1]()) {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String& operator=(const String& rhs) {
        cout << "String &operator=(const String &)" << endl;
        if (this != &rhs) {
            if (_pstr) {
                delete[] _pstr;
            }
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    size_t length() const {
        size_t len = 0;
        if (_pstr) {
            len = strlen(_pstr);
        }

        return len;
    }
    const char* c_str() const {
        if (_pstr) {
            return _pstr;
        } else {
            return nullptr;
        }
    }

    ~String() {
        cout << "~String()" << endl;
        if (_pstr) {
            delete[] _pstr;
            _pstr = nullptr;
        }
    }

    void print() const {
        if (_pstr) {
            cout << "_pstr = " << _pstr << endl;
        } else {
            cout << endl;
        }
    }

   private:
    char* _pstr;
};

void test0() {
    int a = 10;
    int b = 3;
    // cout << &a << endl;
    // cout << &(a += b) << endl;

    // // 字面值常量
    // // &1;  //error

    // // 字符串常量
    // cout << &"hello" << endl;

    String str("hello");
    cout << &str << endl;

    String* ps = new String("wangdao");
    cout << ps << endl;
    delete ps;

    // &String("World");    //error

    // 非const左值引用只能绑定左值
    // int& ref = a;
    // cout << &ref << endl;

    // // const左值引用既可以绑定左值，又可以绑定右值
    // const int& ref2 = b;
    // const int& ref3 = a + b;
    // cout << &ref3 << endl;

    // const int& ref4 = 1;
    // cout << &ref4 << endl;

    // const String& refs = String("world");

    // cout << "1111111111" << endl;
}
void test1() {
    int a = 1, b = 2;
    // 右值引用只能绑定右值，不能绑定左值
    int&& ref = a + b;
    cout << &ref << endl;
}
int main() {
    test0();
    cout << "22222222222222222" << endl;
    return 0;
}