#include <string.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <class T>
T add(T t1, T t2) {
    return t1 + t2;
}

// 针对通用模板解决不了参数类型const char *
// 定义了特化模板
// 特化模板不能脱离于通用模板而存在
// 特化模板的形式还要跟通用模板一致
template <>
const char* add<const char*>(const char* p1, const char* p2) {
    char* temp = new char[strlen(p1) + strlen(p2) + 1]();
    strcpy(temp, p1);
    strcat(temp, p2);
    return temp;
}

void test0() {
    int a = 1, b = 3;
    double c = 3.7, d = 8.6;
    const char* pstr1 = "hello,";
    const char* pstr2 = "world";
    cout << add(a, b) << endl;
    cout << add(c, d) << endl;

    const char* res = add<const char*>(pstr1, pstr2);
    cout << res << endl;
    delete[] res;
}

int main() {
    test0();
    return 0;
}