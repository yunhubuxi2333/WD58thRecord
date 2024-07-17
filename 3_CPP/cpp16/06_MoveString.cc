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
        cout << "String(const String & )" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String(String&& rhs) : _pstr(rhs._pstr) {
        cout << "移动构造" << endl;
        rhs._pstr = nullptr;
    }

    String& operator=(String&& rhs) {
        cout << "移动赋值函数" << endl;
        if (this != &rhs) {  // 自赋值的判断有意义
            delete[] _pstr;
            // 浅拷贝
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        return *this;
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

    void print() const { cout << "_pstr = " << _pstr << endl; }

   private:
    char* _pstr;
};

void test0() {
    String s1 = String("hello");  // 移动构造
    s1 = String("wangdao");       // 移动赋值函数
    s1.print();

    cout << endl;
    String s2("world");
    s1 = s2;  // 移动赋值函数
    s1.print();
}

int main() {
    test0();
    return 0;
}