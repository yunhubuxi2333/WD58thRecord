#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) {  // cout << "Point(int,int)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

void test1() {
    unique_ptr<Point> up(new Point(1, 2));
    unique_ptr<Point> up2(new Point(4, 7));
    unique_ptr<Point> up3(new Point(5, 9));

    vector<unique_ptr<Point>> vec;

    vec.push_back(unique_ptr<Point>(new Point(8, 5)));
    vec.push_back(std::move(up));
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));

    for (int i = 0; i < vec.size(); i++) {
        vec[i]->print();
    }
}

int main() {
    test1();
    return 0;
}