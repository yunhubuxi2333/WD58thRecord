#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

// 类的前向声明
class Point;

class Line {
   public:
    float distance(const Point& lhs, const Point& rhs);
    void setX(Point& rhs, int x);
};

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {}

    void print() const {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

    // 友元的第二种形式
    // 将另一个类的成员函数声明为友元函数
    friend float Line::distance(const Point& lhs, const Point& rhs);
    friend void Line::setX(Point& rhs, int x);

   private:
    int _ix;
    int _iy;
};

// 这种方式割裂了代码
// 使用较少，但是仍然得掌握
float Line::distance(const Point& lhs, const Point& rhs) {
    return sqrt(pow(lhs._ix - rhs._ix, 2) + pow(lhs._iy - rhs._iy, 2));
}

void test0() {
    Point pt(0, 0);
    Point pt2(3, 4);
    Line ll;
    cout << ll.distance(pt, pt2) << endl;
}

int main() {
    test0();
    return 0;
}
