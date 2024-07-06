#include <iostream>
using std::cout;
using std::endl;

void print(int x) { cout << "print:" << x << endl; }

void display(int x) { cout << "display:" << x << endl; }

void show() { cout << "show()" << endl; }

typedef int INT;

// 利用typedef给void(*)(int)这种逻辑类型
// 赋予了新的类型名称Function
// 这种类型的变量就是能够去指向返回类型为void,参数为一个int的函数的函数指针
typedef void (*Function)(int);

void test1() {
    Function f1 = print;
    f1(6);
    f1 = display;
    f1(8);

    Function f2;
    f2 = &display;
    (*f2)(7);
}

void test0() {
    INT a = 10;
    cout << a << endl;

    // 函数指针定义的时候就确定了其能够指向的函数
    // 返回类型、参数信息

    // 省略写法
    void (*p1)(int) = print;
    p1(4);

    p1 = display;
    p1(5);
}

int main() {
    test0();
    return 0;
}