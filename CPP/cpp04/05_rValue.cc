#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix = 10;
    int _iy = 10;
};

void test0() {
    // 能够取地址的叫做左值
    // 不能取地址的叫做右值
    // 右值包括：临时变量（匿名变量）、临时对象（匿名对象）、字面值常量
    int a = 1, b = 2;
    &a;
    &b;
    /* &(a + b);//右值 */
    /* &1; */

    Point pt(1, 2);
    &pt;
    Point(2, 4).print();  // 生命周期只在当前行
    /* &Point(2,4);//匿名对象，右值 */

    // 非const引用只能绑定左值，不能绑定右值
    int& ref = a;
    int& ref2 = b;

    /* int & ref3 = a + b; */
    /* int & ref4 = 1; */

    Point& pref = pt;
    /* Point & pref2 = Point(2,4); */

    // const引用既可以绑定左值，又可以绑定右值
    const int& ref5 = a;
    const int& ref6 = a + b;
    const int& ref7 = 1;

    const Point& pref3 = Point(5, 6);
}

int main(void) {
    test0();
    return 0;
}