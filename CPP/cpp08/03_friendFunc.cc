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

    // 友元的第一种形式
    // 普通函数声明为一个类的友元函数
    // 那么在这个函数种可以访问类的私有成员
    friend float distance(const Point& lhs, const Point& rhs);

   private:
    int _ix;
    int _iy;
};

// 建立一个观念
//  如果函数的参数为对象
//  形参首先想到const引用的形式
float distance(const Point& lhs, const Point& rhs) {
    return sqrt(pow(lhs._ix - rhs._ix, 2) + pow(lhs._iy - rhs._iy, 2));
}

void test0() {
    Point pt(0, 0);
    Point pt2(3, 4);
    cout << distance(pt, pt2) << endl;
}

int main() {
    test0();
    return 0;
}
