#include "String.hpp"

#include <string.h>

#include <iostream>
#include <istream>
#include <ostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#define MAXLINE 1024

String::String() : _pstr(new char[1]()) { cout << "String()" << endl; }

String::String(const char* pstr) : _pstr(new char[strlen(pstr) + 1]()) {
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
}

String::String(const String& rhs) : _pstr(new char[strlen(rhs._pstr) + 1]()) {
    cout << "String(const String &)" << endl;
    strcpy(_pstr, rhs._pstr);
}

String::~String() {
    cout << "~String()" << endl;
    if (_pstr) {
        delete _pstr;
        _pstr = nullptr;
    }
}

// String s1
// s1 = s1
// 赋值运算符，将右值赋给左值，
String& String::operator=(const String& rhs) {
    cout << "String &operator=(const String &)" << endl;
    if (this != &rhs) {
        delete[] _pstr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
}

// 将字符串赋值给string
String& String::operator=(const char* pstr) {
    cout << "String &operator=(const String &)" << endl;
    String tmp(pstr);
    *this = tmp;

    return *this;
}

// 拼接字符串
// s1+=s2
String& String::operator+=(const String& rhs) {
    cout << "String &operator+=(const String &)" << endl;
    String tmp;
    if (tmp._pstr) {
        delete[] tmp._pstr;
    }
    tmp._pstr = new char[strlen(_pstr) + 1]();
    strcpy(tmp._pstr, _pstr);
    delete[] _pstr;

    if (this != &rhs) {
        _pstr = new char[strlen(tmp._pstr) + strlen(rhs._pstr) + 1]();
        strcpy(_pstr, tmp._pstr);
        strcat(_pstr, rhs._pstr);
    } else {
        _pstr = new char[strlen(tmp._pstr) + strlen(tmp._pstr) + 1]();
        strcpy(_pstr, tmp._pstr);
        strcat(_pstr, tmp._pstr);
    }
    return *this;
}

String& String::operator+=(const char* pstr) {
    cout << "String &operator+=(const char*)" << endl;

    String tmp(pstr);
    *this += tmp;

    return *this;
}

char& String::operator[](std::size_t index) {
    if (index < size()) {
        return _pstr[index];
    } else {
        static char nullchar = '\0';
        return nullchar;
    }
}
const char& String::operator[](std::size_t index) const {
    if (index < size()) {
        return _pstr[index];
    } else {
        static char nullchar = '\0';
        return nullchar;
    }
}

std::size_t String::size() const { return strlen(_pstr); }
const char* String::c_str() const { return _pstr; }

bool operator==(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) == 0) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) != 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) < 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) > 0) {
        return true;
    } else {
        return false;
    }
}
bool operator<=(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) < 0) {
        return true;
    } else if (strcmp(lhs._pstr, rhs._pstr) == 0) {
        return true;
    } else {
        return false;
    }
}
bool operator>=(const String& lhs, const String& rhs) {
    if (strcmp(lhs._pstr, rhs._pstr) > 0) {
        return true;
    } else if (strcmp(lhs._pstr, rhs._pstr) == 0) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const String& rhs) {
    os << rhs._pstr;
    return os;
}
std::istream& operator>>(std::istream& is, String& rhs) {
    is >> rhs._pstr;
    return is;
}

String operator+(const String& lhs, const String& rhs) {
    char* tmp1 = new char[strlen(lhs.c_str()) + 1];
    strcpy(tmp1, lhs.c_str());
    char* tmp2 = new char[strlen(rhs.c_str()) + 1];
    strcpy(tmp2, rhs.c_str());
    
    return String(strcat(tmp1, tmp2));
}

String operator+(const String& lhs, const char* str) {
    char* tmp1 = new char[strlen(lhs.c_str()) + 1];
    strcpy(tmp1, lhs.c_str());
    char* tmp2 = new char[strlen(str) + 1];
    strcpy(tmp2, str);

    return String(strcat(tmp1, tmp2));
}

String operator+(const char* str, const String& rhs) {
    char* tmp1 = new char[strlen(str) + 1];
    strcpy(tmp1, str);
    char* tmp2 = new char[strlen(rhs.c_str()) + 1];
    strcpy(tmp2, rhs.c_str());

    return String(strcat(tmp1, tmp2));
}