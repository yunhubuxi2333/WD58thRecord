#include <math.h>
#include <string.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Figure {
   public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
};

void display(Figure& fig) {
    cout << fig.getName() << "的面积是:" << fig.getArea() << endl;
}

// 矩形
class Rectangle : public Figure {
   public:
    Rectangle(double len, double wid) : _length(len), _width(wid) {}

    string getName() const override { return "矩形"; }

    double getArea() const override { return _length * _width; }

   private:
    double _length;
    double _width;
};

// 圆形
class Circle : public Figure {
   public:
    Circle(double rad) : _radius(rad) {}
    string getName() const override { return "圆形"; }

    double getArea() const override { return PI * _radius * _radius; }

   private:
    static constexpr double PI = 3.14;
    double _radius;
};

// 三角形
class Triangle : public Figure {
   public:
    Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {}

    string getName() const override { return "三角形"; }

    double getArea() const override {
        double s = (_a + +_b + _c) / 2;
        return sqrt(s * (s - _a) * (s - _b) * (s - _c));
    }

   private:
    double _a;
    double _b;
    double _c;
};

void test() {
    Rectangle r(10, 20);
    Circle c(15);
    Triangle t(3, 4, 5);
    
    display(r);
    display(c);
    display(t);
}

int main() {
    test();
    return 0;
}