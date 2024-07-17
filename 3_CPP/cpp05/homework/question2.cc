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

   private:
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }
    int _ix;
    int _iy;
};

void test0() {
    Point& pt1 = Point::getInstance();
    cout << &pt1 << endl;
}

int main() {
    test0();
    return 0;
}