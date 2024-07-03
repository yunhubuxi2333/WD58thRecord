#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

void test0() {
    int num = 123, num2 = 456;

    ostringstream oss;
    // 把各种类型的内容都传给了字符串输出流对象
    // 内存中单独准备一块缓冲区
    oss << "num = " << num;
    oss << ", num2 = " << num2 << endl;
    cout << oss.str() << endl;

    string str1("hello");
    str1.append(2, '!');
    str1.append("!!!!");

    str1.append(std::to_string(num));
}
int main() {
    test0();
    return 0;
}