#include <iostream>
using std::cout;
using std::endl;

#define MAX 100

void test0() {
    // const常量本质上还是当成变量处理
    // 但是加上了只读属性
    // 初始化之后不能再修改其值
    const int max = 100;
    cout << max - 1 << endl;

    // const常量必须在初始化时赋初值
    /*const int num;
     *num = 100;
     * */

    const int number1 = 10;
    int const number2 = 20;
}

void test1() {
    int num1 = 1;
    int num2 = 2;
    // const在*的左边
    // 称为指向常量的指针(pointer to const)
    // 能够修改指针的指向，但是不能通过指针修改其指向的值
    const int* p = &num1;
    cout << *p << endl;
    p = &num2;
    cout << *p << endl;

    int const* p2 = &num1;
    // *p2 = 100;
    p2 = &num2;

    const int num = 10;
    const int* p3 = &num;
}

void test2() {
    int num1 = 1;
    int num2 = 2;
    // const在*右边
    // 称为常量指针（const pointer）
    // 从右往左读，先看到const再看到*
    // 可以通过指针修改其指向的值
    // 不能修改其指向
    int* const p = &num1;
    *p = 100;
    cout << num1 << endl;
}

// 数组指针
void test3() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << &arr[0] << endl;
    cout << arr + 1 << endl;

    // 数组指针指向数组的首地址
    // 控制范围是整个数组的空间
    int(*p3)[5] = &arr;
    cout << &arr + 1 << endl;

    for (int i = 0; i < 5; i++) {
        cout << (*p3)[i] << endl;
    }
}

//
int main() {
    std::cout << "Hello world" << std::endl;
    test0;
    return 0;
}
