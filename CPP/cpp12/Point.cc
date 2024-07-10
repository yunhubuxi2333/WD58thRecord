#include <iostream>

using namespace std;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) {}

   private:
    int _ix;
    int _iy;
};
class Point3D : public Point {
   public:
    Point3D(int x, int y, int z) : Point(x, y), _iz(z) {
        cout << "Point3D(int*3)" << endl;
    }

    void display() const {  // 添加新的成员函数
        print();
        cout << _iz << endl;
    }

   private:
    int _iz;  // 添加新的数据成员
};
void test0() {}
int main() {
    test0();
    return 0;
}