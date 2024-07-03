#include <fstream>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;

void test0() {
    ifstream ifs("explicit.cc");

    if (!ifs) {
        cerr << "ifs open file fail!!!" << endl;
        return;
    }

    size_t pos = ifs.tellg();
    cout << pos << endl;

    ifs.seekg(70);
    pos = ifs.tellg();
    cout << pos << endl;

    // 从文件中任意的指定位置开始读取指定长度的内容到内存中
    char* pdata = new char[20]();
    ifs.read(pdata, 10);
    cout << pdata << endl;
    delete[] pdata;
    ifs.close();
}

// 一次性将整个文件的内容读取进来
void test1() {
    ifstream ifs("explicit.cc");  // openmode使用了默认的in模式

    if (!ifs) {
        cerr << "ifs open file fail!!!" << endl;
        return;
    }

    // 要获取文件到底有多少个字符
    ifs.seekg(0, std::ios::end);
    size_t length = ifs.tellg();

    ifs.seekg(0);
    ifs.seekg(0, std::ios::beg);

    char* pdata = new char[length + 1]();
    ifs.read(pdata, length);
    cout << pdata << endl;
}

// 一次性将整个文件的内容读取进来
void test2() {
    // openmode使用了ate模式(打开时就让游标处于文件结尾位置)
    ifstream ifs("explicit.cc", std::ios::ate);

    if (!ifs) {
        cerr << "ifs open file fail!!!" << endl;
        return;
    }

    // 要获取文件到底有多少个字符
    size_t length = ifs.tellg();
    // ifs.seekg(0);
    ifs.seekg(0, std::ios::beg);

    char* pdata = new char[length + 1]();
    ifs.read(pdata, length);
    cout << pdata << endl;
}

int main() {
    test2();
    return 0;
}