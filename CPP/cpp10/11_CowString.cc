#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;
#include "string.h"

class CowString {
   public:
    CowString();
    CowString(const char*);
    CowString(const CowString&);
    CowString& operator=(const CowString&);
    ~CowString();
    const char* c_str() const { return _pstr; }
    int size() const { return strlen(_pstr); }

    int use_count() { return *(int*)(_pstr - kRefCountLength); }

    friend ostream& operator<<(ostream& os, const CowString& rhs);

   private:
    void initRefCount() { *(int*)(_pstr - kRefCountLength) = 1; }
    void increaseRefCount() { ++*(int*)(_pstr - kRefCountLength); }
    void decreaseRefCount() { --*(int*)(_pstr - kRefCountLength); }
    char *malloc(const char *pstr = nullptr){
        if(pstr){
            return new char[strlen(pstr) + 1 + kRefCountLength]() + kRefCountLength;
        }
    }

   private:
    static const int kRefCountLength = 4;
    char* _pstr;
};

ostream& operator<<(ostream& os, const CowString& rhs) {
    if (rhs._pstr) {
        os << rhs._pstr;
    } else {
        os << endl;
    }
    return os;
}

CowString::CowString()
    : _pstr(new char[1 + kRefCountLength]() + kRefCountLength) {
    cout << "CowString()" << endl;
    initRefCount();
}
CowString::CowString(const char * pstr)
:_pstr()
{}
CowString::~CowString() {
    decreaseRefCount();
    if (use_count() == 0) {
        delete[] (_pstr - kRefCountLength);
        _pstr = nullptr;
        cout << ">>>>>>>>>>>>>>>delete heap" << endl;
    }
}

CowString::CowString(const CowString& rhs)
    : _pstr(rhs._pstr)  // 浅拷贝
{
    increaseRefCount();
}
void test0() {
    CowString str1;
    CowString str2 = str1;
    cout << "str1" << str1 << endl;
    cout << "str2" << str2 << endl;

    cout << str1.use_count() << endl;
    cout << str2.use_count() << endl;
}

int main() {
    test0();
    return 0;
}
