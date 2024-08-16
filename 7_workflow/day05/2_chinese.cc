#include <iostream>
#include <string>
using std::cout;
using std::string;
int main() {
    string str = "hi你好";
    for (int i = 0; i < str.size();) {
        // 1000 0000 & ch
        if ((str[i] & 0x80) == 0) {
            cout << "这是一个英文" << str.substr(i, 1) << "\n";
            ++i;
        } else {
            cout << "中文：" << str.substr(i, 3) << "\n";
            i = i + 3;
        }
    }

    return 0;
}