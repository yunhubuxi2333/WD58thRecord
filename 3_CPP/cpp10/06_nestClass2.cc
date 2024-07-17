#include <iostream>
using std::cout;
using std::endl;

class Line {
    class Point {
       public:
        Point(int x = 0, int y = 0) : _ix(x), _iy(y) {}
        ~Point() {}

        void getLine(const Line& rhs) {
            // 不需要友元声明的支持
            // 可以直接通过Line对象访问私有成员
            rhs._pt1;
            rhs._lx;
            // 通过Line类名作用域直接访问Line的私有静态数据成员
            Line::_ly;
        }

        void print() { cout << "(" << _ix << "," << _iy << ")"; }

        friend class Line;

       private:
        int _ix;
        int _iy;
        static int _iz;
    };

   public:
    Line(int x1, int y1, int x2, int y2) : _pt1(x1, y1), _pt2(x2, y2) {}
    ~Line() {}

    void getPoint() {
        _pt1.print();
        _pt1._ix;
        Point::_iz;
    }

    void printLine() {
        _pt1.print();
        cout << "----------->";
        _pt2.print();
        cout << endl;
    }

   private:
    Point _pt1;
    Point _pt2;
    double _lx = 100;
    static double _ly;
};

int Line::Point::_iz = 10;
double Line::_ly = 20;

void test0() {
    Line ll(1, 2, 3, 4);

    ll.printLine();
}

int main() {
    test0();
    return 0;
}