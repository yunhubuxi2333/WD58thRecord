#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    // explicit//禁止隐式转换
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }
    ~Point() { cout << "~Point()" << endl; }

    Point(const Point& rhs) : _ix(rhs._ix), _iy(rhs._iy) {}
    Point& operator=(const Point& rhs) {
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }

    void print() const {
        cout << endl;
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
        cout << endl;
    }

   private:
    int _ix;
    int _iy;
};

void test0() {
    Point pt(1, 8);
    Point pt2(2);
    Point pt3(1);

    pt3.print();

    // 隐式转换
    // Point pt4 = Point(4);
    Point pt4 = {4, 5};

    pt4.print();

    pt3 = Point(7);

    pt3.print();

    pt3 = 7;
    
    pt3.print();
}

int main() {
    test0();
    return 0;
}