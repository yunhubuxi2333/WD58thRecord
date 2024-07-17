#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 函数模板
template <class T>
T add(T t1, T t2) {
    return t1 + t2;
}

// 在调用时实例化出相应的模板函数
// 编译时生成这段代码，不用手动定义
// short add(short t1, short t2) { return t1 + t2; }

void test0() {
    short s1 = 1, s2 = 2;
    int i1 = 3, i2 = 4;
    long l1 = 5, l2 = 6;
    double d1 = 1.6, d2 = 2.8;
    string str1("hello,");
    string str2("world");

    cout << "add(s1,s2):" << add(s1, s2) << endl;
    cout << "add(i1,i2):" << add(i1, i2) << endl;
    cout << "add(l1,l2): " << add(l1, l2) << endl;
    cout << "add(d1,d2): " << add(d1, d2) << endl;
    cout << "add(str1,str2): " << add(str1, str2) << endl;

    cout << endl;
    // 显式实例化
    cout << "add(d1,d2): " << add<int>(d1, d2) << endl;
}

int main() {
    test0();

    return 0;
}