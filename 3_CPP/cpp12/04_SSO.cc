#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0() {
    string str1("hello,world!!!!");
    string str2("hello,world!!!!!!!!!!");
    cout << sizeof(string) << endl;
    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl;

    cout << &str1 << endl;
    printf("%p\n", &str1[0]);
    cout << endl;

    cout << &str2 << endl;
    printf("%p\n", &str2[2]);
    cout << endl;

    cout << str1.size() << endl;
    cout << str1.capacity() << endl;
    cout << endl;

    cout << str2.size() << endl;
    cout << str2.capacity() << endl;
    cout << endl;
}

int main() {
    test0();
    return 0;
}
