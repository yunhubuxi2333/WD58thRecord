#include <iostream>
using std::cout;
using std::endl;

double division(double x, double y) {
    if (y == 0) throw "Division by zero";
    if (x == 0) throw 4.8;
    return x / y;
}

void test0() {
    try {
        //cout << division(9, 0) << endl;  // throw "Division by zero"
                                         // 发生异常，try中接下来的语句不会执行
        //cout << division(0, 100) << endl;     // throw 4.8
        cout << division(1000, 100) << endl;  // 正常
    } catch (const char* msg) {               // catch匹配的是异常类型
        cout << msg << endl;
        cout << "hello,what's your problem?" << endl;
    } catch (double a) {
        cout << a << endl;
        cout << "please change a num !" << endl;
    }
    cout << "over" << endl;
}
int main() {
    test0();
    return 0;
}
