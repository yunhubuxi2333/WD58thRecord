#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class CowString {
   public:
    CowString();
    CowString(const char*);
    CowString(const CowString&);
    CowString& operator=(const CowString&);
    ~CowString();

    const char* c_str() const { return _pstr; }
    size_t size() const { return strlen(_pstr); }

    int use_count() { return *(int*)(_pstr - kRefCountLength); }

    char& operator[](size_t idx);

    friend ostream& operator<<(ostream& os, const CowString& rhs);

   private:
    void initRefCount() { *(int*)(_pstr - kRefCountLength) = 1; }
    void increaseRefCount() { ++*(int*)(_pstr - kRefCountLength); }
    void decreaseRefCount() { --*(int*)(_pstr - kRefCountLength); }
    char* malloc(const char* pstr = nullptr) {
        if (pstr) {
            return new char[strlen(pstr) + 1 + kRefCountLength]() +
                   kRefCountLength;
        } else {
            return new char[1 + kRefCountLength]() + kRefCountLength;
        }
    }

    void release() {
        decreaseRefCount();
        if (use_count == 0) {
            delete[] (_pstr - kRefCountLength);
            _pstr = nullptr;
            cout << ">>>>delete heap" << endl;
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

CowString::CowString() : _pstr(malloc()) { initRefCount(); }

CowString::CowString(const char* pstr) : _pstr(malloc(pstr)) {
    strcpy(_pstr, pstr);
    initRefCount();
}

CowString::~CowString() { release(); }

CowString::CowString(const CowString& rhs) : _pstr(rhs._pstr) {
    increaseRefCount();
}

CowString&CowString::operator=(const CowString & rhs){
    if()
}
void test0() {}

int main() {
    test0();

    return 0;
}