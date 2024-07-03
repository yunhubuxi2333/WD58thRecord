#include <fstream>
#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

void test0() {
    // 文件输出流对象绑定的文件可以不存在
    // 如果不存在，会将这个文件创建出来

    // 如果文件存在，每次写入内容都会将文件中
    // 原本的内容清空，再写入内容
    ofstream ofs("result.txt", std::ios::app);

    if (!ofs) {
        cerr << "ofstream open file failed!!!!" << endl;
        return;
    }
    string line("hello,world\n");
    ofs << line;

    ofs.close();
}

int main() {
    test0();
    return 0;
}