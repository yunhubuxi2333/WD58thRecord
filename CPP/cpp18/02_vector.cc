#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0() {
    // vector<int> number;         // 1、创建无参对象
    // vector<int> number();       // 此处number是函数名
    // vector<int> number(10, 3);  // 2.count个value

    int arr[10] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 10};
    // 3、迭代器范围的初始化方式
    vector<int> number(arr, arr + 10);
    // 4、拷贝或者移动构造函数
    vector<int> number2 = number;
    // 5、使用大括号形式
    // vector<int> number{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 遍历
    for (size_t idx = 0; idx != number.size(); ++idx) {
        cout << number[idx] << "  ";
    }
    cout << endl;

    vector<int>::iterator it;
    for (it = number.begin(); it != number.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;

    // n + gcc,可以注释n行，取消直接u
    vector<int>::iterator it2 = number.begin();
    for (; it2 != number.end(); ++it2) {
        cout << *it2 << "  ";
    }
    cout << endl;

    for (auto& elem : number) {
        cout << elem << "  ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    test0();
    return 0;
}