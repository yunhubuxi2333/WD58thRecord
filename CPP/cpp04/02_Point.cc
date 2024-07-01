#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {  // 有参构造函数
        cout << "Point(int,int)" << endl;
    }
    ~Point() { cout << "~Point()" << endl; }

    Point(const Point& rhs) : _ix(rhs._ix), _iy(rhs._iy) {  // 拷贝构造函数
        cout << "Point(const Point&)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

void test0() {
    int x = 1;
    int y = x;
    int z(x);

    cout << y << endl;
    cout << z << endl;

    Point pt(10, 8);
    // 利用一个已经存在的对象用复制的方式创建出新的对象
    // 调用拷贝构造，用=连接是为了跟内置类型保持一致
    Point pt2 = pt;
    pt2.print();
}

int main() {
    test0();

    return 0;
}