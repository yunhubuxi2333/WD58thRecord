#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point() {
        cout << "Point()" << endl;
        _ix = 0;
        _iy = 0;
    }

    Point(int x) {
        cout << "Point(int)" << endl;
        _ix = x;
        _iy = x + 10;
    }

    Point(int x, int y) {
        cout << "Point(int,int)" << endl;
        _ix = x;
        _iy = y;
    }

    void setX(int x) { _ix = x; }
    void setY(int y) { _iy = y; }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};
void test0() {
    int a;
    a = 10;
    int b = 10;
    cout << b << endl;

    // 调用有参构造
    Point pt2(1, 7);
    pt2.print();

    // 调用无参构造
    Point pt;
    pt.print();

    Point pt3(10);
    pt3.print();
}
int main() {
    test0();
    return 0;
}