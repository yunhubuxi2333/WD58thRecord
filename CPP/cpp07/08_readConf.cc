#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;

void readConfig(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "ifstream open file failed!!!" << endl;
        return;
    }

    string line;
    string key;
    string value;
    while (getline(ifs, line)) {
        // 字符串输入流相当于在内存中单独准备一块缓冲区
        // 将一行内容缓存下来
        istringstream iss(line);
        iss >> key >> value;
        cout << key << "--------------------->" << value << endl;
    }
}

void test0() { readConfig("myserver.conf"); }

int main() {
    test0();
    return 0;
}