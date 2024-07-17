#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

#define MAX "hello"

void test0() {
    char arr[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << arr << endl;      // "hello"
    cout << arr + 1 << endl;  // "ello"

    char arr2[] = {'h', 'e', 'l', 'l', 'o'};  // "hellohello"没有'\0'
    char arr3[] = "hello";
    cout << arr2 << endl;
    cout << arr3 << endl;

    const char* pstr = "world";  // 文字常量区
    cout << pstr << endl;

    char* p = new char[strlen(pstr) + 1]();  // 堆区
    strcpy(p, pstr);
    cout << p << endl;
    delete[] p;
    p = nullptr;
}

void test1() {
    int a = 1, b = 2, c = 3;
    int arr[3] = {a, b, c};
    cout << &a << endl;
    cout << arr << endl;
}

int main() {
    test0();
    test1();
    return 0;
}
