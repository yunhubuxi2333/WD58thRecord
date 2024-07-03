#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void test0() {
    ifstream ifs;
    // 文件输入流是要将数据从文件中读取到文件
    // 流对象绑定的这个文件必须要存在
    // 否则流对象进入failbit状态，无法正常工作
    ifs.open("01_explicit.cc");

    if (!ifs) {
        cerr << "ifstream open file failed!!!" << endl;
        return;
    }

    string word;
    // 将整个文件以单词的形式输出了出来

    // 输入流运算符默认以空格符作为分隔符
    // ifs >> word;
    // cout << word << endl;
    // ifs >> word;
    // cout << word << endl;

    while (ifs >> word) {
        cout << word << endl;
    }
}

int main(void) {
    test0();

    return 0;
}