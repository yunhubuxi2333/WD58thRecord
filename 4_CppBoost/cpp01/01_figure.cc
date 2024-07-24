#include <math.h>

#include <iostream>

using std::cout;
using std::endl;

// 面向对象的设计原则：开放闭合原则
// 对扩展开放，对修改关闭
//
// 抽象类，作为接口使用
class Figure {
   public:
    // 纯虚函数
    virtual void display() const = 0;
    virtual double area() const = 0;
};

class Rectangle : public Figure {
   public:
    Rectangle(double length = 0, double width = 0)
        : _length(length), _width(width) {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display() const override { cout << "Rectangle"; }

    double area() const override { return _length * _width; }

    ~Rectangle() { cout << "~Rectangle()" << endl; }

   private:
    double _length;
    double _width;
};

class Circle : public Figure {
   public:
    Circle(double radius = 0) : _radius(radius) {
        cout << "Circle(double = 0)" << endl;
    }

    void display() const override { cout << "Circle"; }

    double area() const override {
        return 3.14 * _radius * _radius;
        ;
    }

    ~Circle() { cout << "~Circle()" << endl; }

   private:
    double _radius;
};

class Triangle : public Figure {
   public:
    Triangle(double a = 0, double b = 0, double c = 0) : _a(a), _b(b), _c(c) {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void display() const override { cout << "Triangle"; }

    double area() const override {
        // 海伦公式
        double tmp = (_a + _b + _c) / 2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

    ~Triangle() { cout << "~Triangle()" << endl; }

   private:
    double _a;
    double _b;
    double _c;
};

void func(Figure* pfig) {
    pfig->display();
    cout << "的面积 : " << pfig->area() << endl;
}

int main(int argc, char** argv) {
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    func(&rectangle);
    func(&circle);
    func(&triangle);

    return 0;
}
