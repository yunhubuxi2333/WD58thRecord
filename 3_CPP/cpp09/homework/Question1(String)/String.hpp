#ifndef __String_HPP__
#define __String_HPP__
#include <iostream>

class String {
   public:
    String();
    String(const char* pstr);
    String(const String& rhs);
    ~String();
    String& operator=(const String& rhs);
    String& operator=(const char* pstr);

    String& operator+=(const String& rhs);
    String& operator+=(const char* pstr);

    char& operator[](std::size_t index);
    const char& operator[](std::size_t index) const;

    std::size_t size() const;
    const char* c_str() const;

    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);

    friend bool operator<(const String& lhs, const String& rhs);
    friend bool operator>(const String& lhs, const String& rhs);
    friend bool operator<=(const String& lhs, const String& rhs);
    friend bool operator>=(const String& lhs, const String& rhs);

    friend std::ostream& operator<<(std::ostream& os, const String& rhs);
    friend std::istream& operator>>(std::istream& is, String& rhs);

   private:
    char* _pstr;
};

String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, const char* pstr);
String operator+(const char* pstr, const String& rhs);

#endif