#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Line {
    // Point称为Line的成员类型
    class Point {
       public:
        Point(int x = 0, int y = 0) : _ix(x), _iy(y) {}

        ~Point() {}

        friend ostream& operator<<(ostream& os, const Line::Point& rhs);

       private:
        int _ix;
        int _iy;
    };

   public:
    Line(int x1, int y1, int x2, int y2) : _pt1(x1, y1), _pt2(x2, y2) {}
    ~Line() {}

    friend ostream& operator<<(ostream& os, const Line& rhs);
    friend ostream& operator<<(ostream& os, const Point& rhs);

   private:
    Point _pt1;
    Point _pt2;
};

ostream& operator<<(ostream& os, const Line::Point& rhs) {
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}

ostream& operator<<(ostream& os, const Line& rhs) {
    os << rhs._pt1 << "--------->" << rhs._pt2;
    return os;
}

void test0() {
    Line ll(1, 2, 3, 4);
    cout << ll << endl;
}

int main(void) {
    test0();
    return 0;
}