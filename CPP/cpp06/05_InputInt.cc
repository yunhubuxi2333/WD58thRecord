#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

void InputInt(int& number) {
    cout << "请输入一个int型的数据" << endl;

    // 逗号表达式整体的返回值就是最后一个逗号后面的表达式的返回值
    // 逗号表达式前面的内容会执行，但不影响最终判断条件

    while (cin >> number, !cin.eof()) {
        if (cin.bad()) {
            cout << "cin has broken!" << endl;
            return;
        } else if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "请输入一个int型的数据,看清楚一点!" << endl;
        } else {
            cout << "num:" << number << endl;
            break;
        }
    }
}

void test0() {
    int num = 10;
    InputInt(num);
}

void test1() {
    int num = 0;
    cin >> num;

    // if (cin.good()) {
    // cin的状态是goodbit状态，在作为判断条件时会隐式转换成true
    if (cin) {
        cout << "hello" << endl;
    }
}

void test2() {
    int num = 0, num2 = 0;
    // 输入流运算符默认以换行符、空格符、制表符作为分隔符
    // cin对象完成一次输入后，返回值就是cin对象本身
    cout << &cin << endl;
    cout << &(cin >> num) << endl;

    // 执行过程相当于(cin>>num)>>num2
    cin >> num >> num2;
    cout << "num: " << num << endl;
    cout << "num2: " << num2 << endl;
}

int main() {
    // test0();
    // test1();
    test2();

    return 0;
}