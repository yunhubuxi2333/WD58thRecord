#include <iostream>
#include <limits>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

void printStreamStatus(istream& is) {
    cout << "is' goodbit:" << is.good() << endl;
    cout << "is' badbit:" << is.bad() << endl;
    cout << "is' failbit:" << is.fail() << endl;
    cout << "is' eofbit:" << is.eof() << endl;
}

void test0() {
    printStreamStatus(cin);

    int num = 10;
    cout << "num:";
    cin >> num;
    cout << "num:" << num << endl;

    printStreamStatus(cin);

    // 如果经过了第一次的输入，使得标准输入流进入failbit/eofbit状态
    // 希望能够恢复流的状态
    cout << endl;
    if (!cin.good()) {
        cin.clear();  // 恢复流的状态
        // 还需要清空缓冲区中的内容
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << endl;
    string line;
    cout << "line:";
    cin >> line;
    cout << "line:" << line << endl;

    int num2 = 2;
    cout << "num2:";
    cin >> num2;
    cout << "num2:" << num2 << endl;

    printStreamStatus(cin);
}

int main(void) {
    test0();
    return 0;
}