#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point()
        // 初始化中对数据成员进行初始化是严格的初始化
        : _ix(1000)  // int _ix = 0;
          ,
          _iy(10)  // int _iy = 0;
    {
        cout << "Point()" << endl;
    }

    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }

    void setX(int x) { _ix = x; }
    void setY(int y) { _iy = y; }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix = 10;
    int _iy = 10;
};

void test1() { cout << sizeof(Point) << endl; }

void test0() {
    int a;
    a = 10;

    int b = 10;
    cout << b << endl;

    // 调用有参构造
    Point pt2(1, 7);
    pt2.print();

    // 调用无参构造的方式
    Point pt;
    pt.print();

    Point pt3(10);
    pt3.print();
}

int main() {
    test0();
    test1();        //对象的大小就是其数据成员的大小

    return 0;
}