#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test0() {
    vector<int> number1;         // 1、无参构造函数
    vector<int> number2(10, 3);  // 2、count个value
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    vector<int> number3(arr, arr + 10);  // 3、迭代器范围的初始化
    vector<int> number4(number3);        // 4、拷贝或者移动构造函数
    vector<int> number5{11, 22, 33, 44, 55};  // 5、大括号形式
    for (auto& elem : number1) {
        cout << elem << "  ";
    }
    cout << endl;
    for (auto& elem : number2) {
        cout << elem << "  ";
    }
    cout << endl;
    for (auto& elem : number3) {
        cout << elem << "  ";
    }
    cout << endl;
    for (auto& elem : number4) {
        cout << elem << "  ";
    }
    cout << endl;
    for (auto& elem : number5) {
        cout << elem << "  ";
    }
    cout << endl;
}

int main() {
    test0();
    return 0;
}