#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(double x, double y) : _x(x), _y(y) {}

    // 定义一个成员函数模板
    // 将_x转换成目标类型
    template <class T = int>
    T convert() {
        return (T)_x;
    }

    template <class T, int a = 1>
    T add(T b);

    void print() const { cout << "(" << _x << "," << _y << ")" << endl; }

   private:
    double _x;
    double _y;
};

// 成员函数模板在类外实现
// 需要写上模板声明的完整形式
template <class T, int a>
T Point::add(T b) {
    return _x + _y + a + b;
}

void test0() {
    Point pt(1.1, 2.2);
    cout << pt.convert() << endl;
    pt.print();

    pt.add<double, 10>(3.3);
    pt.add(3.3);
}

int main() {
    test0();
    return 0;
}