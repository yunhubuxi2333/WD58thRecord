#include <iostream>
using std::cout;
using std::endl;

class DDD {
   public:
    void print(int x) { cout << "FFF:print:" << x << endl; }
};

class FFF {
   public:
    void print(int x) { cout << "FFF::print:" << x << endl; }
    void display(int x) { cout << "FFF::display:" << x << endl; }
    void func() { cout << "FFF::func()" << endl; }
    int func2(int x) {
        cout << "FFF::func2:" << x << endl;
        return x;
    }
    static void show(int x) { cout << "FFF::show:" << x << endl; }
};

void print(int x) { cout << "print:" << x << endl; }

void display(int x) { cout << "display:" << x << endl; }

void show() { cout << "show()" << endl; }

typedef void (*Function)(int);
// 对一类特定的成员函数指针归结出了新的类型名称
// MemFunction类型的变量就是这种特定的成员函数指针变量
typedef void (FFF::*MemFunction)(int);

void test0() {
    // 普通函数和静态成员函数不需要通过对象调用
    // 非静态成员函数需要通过对象调用
    Function f1 = FFF::show;
    f1(50);

    // 普通函数指针不能指向一个类的非静态成员函数
    //  f1 = &FFF::print;   //error

    // 需要定义一个成员函数指针才能指向类的非静态成员函数
    // 注意：
    // （1）在指针名前面也要加上类作用域
    // （2）必须使用完整形式
    // 定义成员函数指针时就已经确定了能够指向的成员函数
    // 的返回类型、参数信息、类的信息
    void (FFF::*f2)(int) = &FFF::print;
    FFF fff;
    //.* 成员指针运算符的形式之一
    (fff.*f2)(26);

    f2 = &FFF::display;
    (fff.*f2)(37);

    // f2 = &FFF::func;
    // f2 = &FFF::func2;
    // f2 = &DDD::print;

    void (FFF::*f3)(int);
    f3 = &FFF::display;
    (fff.*f3)(35);

    MemFunction f4;
    f4 = &FFF::print;
    (fff.*f4)(54);

    //.和->都叫成员访问运算符
    FFF* fp = new FFF();
    //->*成员指针运算符的形式之二
    // 运算符名称中的指针说的是f4是一个指针（成员函数指针）
    (fp->*f4)(75);

    fp = nullptr;
    (fp->*f4)(78);
}

void test1() {
    Function f1 = print;
    f1(6);

    f1 = display;
    f1(4);
}

int main(void) {
    test0();
    return 0;
}