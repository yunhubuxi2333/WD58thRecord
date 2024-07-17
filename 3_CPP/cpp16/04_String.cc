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
            cout << "_pstr" << _pstr << endl;
        } else {
            cout << endl;
        }
    }

   private:
    char* _pstr;
};

void test0() {
    String s1("hello");
    String s2 = s1;
    s1.print();
    s2.print();

    // 先构造，再拷贝构造
    // 利用"hello"这个字符创建了一个临时对象
    // 并复制给了s3
    // 这一步实际上new了两次
    
    String s3 = "hello";
}

int main() {
    test0();
    return 0;
}