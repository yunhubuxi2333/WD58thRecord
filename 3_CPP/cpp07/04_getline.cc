#include <strings.h>

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
        cerr << "ifstream open file failed" << endl;
        return;
    }

    // 1.兼容C的方式(不常用)
    char buff[100] = {0};
    while (ifs.getline(buff, sizeof(buff))) {
        cout << buff << endl;
        bzero(buff, sizeof(buff));  // 完成一次读取之后清空
    }
    cout << endl;

    ifs.clear();   // 将流状态从eofbit恢复为goodbit
    ifs.seekg(0);  // 将文件游标移动到开头

    // 2.C++方式，工作中更常用，采用string提供的getline
    string line;
    // 这个getline函数的返回值就是ifs
    while (getline(ifs, line)) {
        cout << line << endl;
    }

    // 关闭流，规范操作
    ifs.close();
}

int main(void) {
    test0();
    return 0;
}