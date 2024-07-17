#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

class String {
   public:
    String() : _size(0), _pstr(new char[15]()) { cout << "String()" << endl; }

    String(const char* pstr)
        : _size(strlen(pstr)), _pstr(new char[strlen(pstr) + 1]()) {
        cout << "String()" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String& rhs)
        : _size(rhs._size), _pstr(new char[strlen(rhs._pstr) + 1]()) {
        strcpy(_pstr, rhs._pstr);
    }

    String& operator=(const String& rhs) {
        if (strlen(_pstr) < strlen(rhs._pstr)) {
            free(_pstr);
            _pstr = new char[strlen(rhs._pstr) + 1]();
        }
        strcpy(_pstr, rhs._pstr);
        _size = rhs._size;
        _pstr[_size] = '\0';

        return *this;
    }

    ~String() {
        free(_pstr);
        _pstr = nullptr;
    }

    void print() { cout << _pstr << endl; }

    size_t length() const { return _size; }

    const char* c_str() const { return _pstr; }

   private:
    int _size;
    char* _pstr;
};

int main() {
    String str1;
    cout << "str1" << endl;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    cout << "str2" << endl;
    str2.print();
    cout << "str3" << endl;
    str3.print();

    String str4 = str3;
    cout << "str4" << endl;
    str4.print();

    str4 = str2;
    cout << "str4" << endl;
    str4.print();

    return 0;
}