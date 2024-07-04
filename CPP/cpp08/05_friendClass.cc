#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {}

    void print() const {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

    // 友元的第三种形式————友元类
    // 将line类声明为Point的友元类
    // 那么Line中所有的成员函数都可以访问Point的私有成员
    friend class Line;

   private:
    int _ix;
    int _iy;
};

class Line {
   public:
    float distance(const Point& lhs, const Point& rhs) {
        return sqrt(pow(lhs._ix - rhs._ix, 2) + pow(lhs._iy - rhs._iy, 2));
    }

    void setX(Point& rhs, int x) { rhs._ix = x; }
};

void test0() {
    Point pt(0, 0);
    Point pt2(3, 4);
    Line ll;
    cout << ll.distance(pt, pt2) << endl;

    int num = 10;
    cout << sizeof num << endl;
    cout << sizeof pt << endl;
}

int main() {
    test0();
    return 0;
}
