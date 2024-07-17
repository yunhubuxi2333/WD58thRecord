#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

void test0() {
    string s("123 456");
    int num = 0;
    int num2 = 0;
    // 将字符串内容传递给了字符串输入流对象
    istringstream iss(s);

    // 这里输入流运算符默认以空格符作为了分隔符
    iss >> num >> num2;
    cout << "num: " << num << endl;
    cout << "num2: " << num2 << endl;
}

int main() {
    test0();
    return 0;
}