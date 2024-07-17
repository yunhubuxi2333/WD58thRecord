#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) { cout << "Point(int,int)" << endl; }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

void test1() {
    unique_ptr<Point> up(new Point(1, 2));
    up->print();
    (*up).print();

    unique_ptr<Point> up2(new Point(4, 7));
    unique_ptr<Point> up3(new Point(5, 9));

    vector<unique_ptr<Point>> vec;

    // unique_ptr作为容器元素，必须以右值的形式加入
    // 使用移动构造创建出新的unique_ptr对象作为容器元素
    // 移交了对原本管理的资源管理权
    vec.push_back(unique_ptr<Point>(new Point(8, 5)));
    vec[0]->print();

    vec.push_back(std::move(up));
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));
    vec[1]->print();
    vec[2]->print();
    vec[3]->print();
    // up->print();
    // up2->print();
    // up3->print();
}

void test0() {
    unique_ptr<int> up(new int(10));

    // unique_ptr不能进行复制赋值操作
    // 对象语义

    unique_ptr<int> up2(new int(10));

    cout << *up << endl;
    cout << *up2 << endl;
    cout << up.get() << endl;
}

int main() {
    test1();
    return 0;
}