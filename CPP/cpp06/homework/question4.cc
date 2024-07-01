#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) {  // 有参构造函数
        cout << "Point(int,int)" << endl;
    }

    ~Point() {
        // cout << "~Point()" << endl;
    }

    Point(const Point& rhs) : _ix(rhs._ix), _iy(rhs._iy) {  // 拷贝构造函数
        cout << "Point(const Point&)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

void test0() {
    Point pt1(1, 2);
    Point pt2(3, 4);
    Point pt3(5, 6);
    Point pt4(7, 8);

    vector<Point> pts{pt1, pt2, pt3, pt4};

    for (auto& ele : pts) {
        ele.print();
    }
    cout << endl;
}

int main(void) {
    test0();
    return 0;
}