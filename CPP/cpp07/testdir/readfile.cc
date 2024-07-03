#include <fstream>
#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void test0() {
    string filename = "01_explicit.cc";
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "ifs open file failed!!!" << endl;
        return;
    }

    size_t pos = ifs.tellg();
    cout << pos << endl;

    ifs.seekg(60);
    pos = ifs.tellg();
    cout << pos << endl;

    // 从文件任意指定位置读取指定长度的内容到内存中
    char* pdata = new char[20]();
    ifs.read(pdata, 10);
    cout << pdata << endl;

    delete[] pdata;
    ifs.close();
}

int main() {
    test0();
    return 0;
}