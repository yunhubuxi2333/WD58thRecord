#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    static Point& getInstance() {
        static Point pt(1, 2);
        return pt;
    }

    ~Point() { cout << "~Point()" << endl; }

    Point& operator=(const Point& rhs) {
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }
    void print() const {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

   private:
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point& rhs) : _ix(rhs._ix), _iy(rhs._iy) {
        cout << "Point(const Point &)" << endl;
    }

   private:
    int _ix;
    int _iy;
};

void test0() {
    Point& pt1 = Point::getInstance();
    Point& pt2 = Point::getInstance();
    cout << &pt1 << endl;
    cout << &pt2 << endl;
}

int main() {
    test0();
    return 0;
}