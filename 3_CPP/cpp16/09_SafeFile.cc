#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class SafeFile {
   public:
    // 在构造函数中托管资源
    SafeFile(FILE* fp) : _fp(fp) { cout << "SafeFile(FILE*)" << endl; }

    // 提供一些访问资源的方式
    // 比如 对文件进行写操作

    void write(const string& msg) { fwrite(msg.c_str(), 1, msg.size(), _fp); }

    ~SafeFile() {
        cout << "~SafeFile()" << endl;
        if (_fp) {
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }

   private:
    FILE* _fp;
};

void test0() {
    // 有double free的风险
    FILE* f = fopen("wd.txt", "a+");
    SafeFile sf(f);
    sf.write("hello,world\n");
}

// 推荐使用方式，类似于单例
void test1() {
    SafeFile sf(fopen("wd.txt", "a+"));
    sf.write("hello,world\n");
}

int main() {
    test0();
    return 0;
}