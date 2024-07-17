#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {  // 有参构造函数
        cout << "Point(int,int)" << endl;
    }

    ~Point() { cout << "~Point()" << endl; }

    Point(const Point& rhs) : _ix(rhs._ix), _iy(rhs._iy) {
        cout << "Point(const Point&)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix = 10;
    int _iy = 10;
};

// 拷贝构造的调用时机之二
// 当函数的实参和形参都是对象时
// 利用实参初始化形参，相当于是值传递
// 会发生复制
//
// 为了避免这次多余的复制，可以将形参改为引用
/* void func1(Point & p) */
void func1(Point p) { p.print(); }

void test1() {
    Point pt(1, 8);
    func1(pt);
}

// 拷贝构造的第三种调用时机
// 函数的返回值是对象时
// 函数体中执行return语句时会发生复制
//
// 为了避免多余的复制，可以将函数的返回值改为引用
// 同时，要确保引用绑定的对象本体生命周期比函数更长
Point pt1(7, 8);
/* Point & func2(){ */
Point func2() { return pt1; }

void test2() { func2(); }

void test0() {
    Point pt(10, 8);
    // 利用一个已经存在的对象用复制的方式创建出新的对象
    // 调用拷贝构造，用=连接是为了跟内置类型保持一致
    Point pt2 = pt;
    pt2.print();
}

int main(void) {
    test2();
    return 0;
}