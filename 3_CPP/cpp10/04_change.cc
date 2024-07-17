#include <iostream>
using std::cout;
using std::endl;

class Complex;  // 前向声明

class Point {
   public:
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }

    Point(const Complex& rhs);

    Point& operator=(int x) {
        cout << "特殊的赋值运算符函数" << endl;
        _ix = x;
        return *this;
    }

    ~Point() {}

    // 类型转换函数
    operator int() { return _ix + _iy; }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }

    operator Point() {
        cout << "operator Point()" << endl;
        return Point(_real, _image);
    }

    friend class Point;

   private:
    int _real;
    int _image;
};

Point::Point(const Complex& rhs) : _ix(rhs._real), _iy(rhs._image) {
    cout << "特殊的构造函数Complex" << endl;
}

void test0() {
    Point pt(1, 2);
    pt.print();

    // 如果有合适的赋值运算符函数支持，就直接处理
    // 如果没有，就通过隐式转换的途径
    // 将一个int型数据“转换”成了Point对象
    pt = 3;
    pt.print();
}

// 将自定义类型对象转换成内置类型
void test1() {
    int a = 10;
    Point pt(2, 4);
    // 需要将Point对象转换成int型变量
    a = pt;
    a = pt.operator int();  // 本质
    cout << a << endl;
    pt.print();
}

void test2() {
    Point pt(1, 2);
    Complex cx(3, 4);

    pt = cx;  // 优先调用赋值运算符函数，其次类型转换的优先级高于隐式转换
    // pt = Point(cx);
    pt.operator=(cx);
    // pt = cx.operator Point();

    pt.print();
    cx.print();
}

int main() {
    test2();
    return 0;
}