#include <math.h>

#include <functional>
#include <iostream>

using std::bind;
using std::cout;
using std::endl;
using std::function;

// 面向对象的方式：继承+ 虚函数（纯虚函数）可以体现出多态，动态多态
// 基于对象的方式：std::bind + std::function也可以实现多态，静态多态

class Figure {
   public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<double()>;

    DisplayCallback _displayCallback;
    AreaCallback _areaCallback;

    // cb是右值引用，可以接受/绑定/识别右值，但是本身在此处是左值
    void setDisplayCallback(DisplayCallback&& cb) {
        _displayCallback = std::move(cb);
    }

    void setAreaCallback(AreaCallback&& cb) { _areaCallback = std::move(cb); }

    void handleDisplayCallback() const {
        if (_displayCallback) {
            _displayCallback();
        }
    }

    double handleAreaCallback() const {
        if (_areaCallback) {
            _areaCallback();
        } else {
            return 0.0;
        }
    }
};

class Rectangle {
   public:
    Rectangle(double length = 0, double width = 0)
        : _length(length), _width(width) {
        cout << "Rectangle(double = 0,double = 0)" << endl;
    }

    void display(int x) const { cout << "Rectangle"; }
    double area() const { return _length * _width; }
    ~Rectangle() { cout << "~Rectangle()" << endl; }

   private:
    double _length;
    double _width;
};

class Circle {
   public:
    Circle(double radius = 0) : _radius(radius) {
        cout << "Circle(double = 0)" << endl;
    }
    void print() const { cout << "Circle"; }
    double printArea() const { return 3.14 * _radius * _radius; }
    ~Circle() { cout << "~Circle()" << endl; }

   private:
    double _radius;
};

class Triangle {
   public:
    Triangle(double a = 0, double b = 0, double c = 0) : _a(a), _b(b), _c(c) {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void show() const { cout << "Triangle"; }

    double showArea() const {
        // 海伦公式
        double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

    ~Triangle() { cout << "~Triangle()" << endl; }

   private:
    double _a;
    double _b;
    double _c;
};

void func(const Figure& fig) {
    fig.handleDisplayCallback();
    cout << "的面积是" << fig.handleAreaCallback() << endl;
}

int main() {
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    cout << endl;
    Figure fig;
    fig.setDisplayCallback(bind(&Rectangle::display, &rectangle, 100));
    fig.setAreaCallback(bind(&Rectangle::area, &rectangle));
    func(fig);

    // cout << endl;
    // fig.setDisplayCallback(bind(&Circle::print, &circle));
    // fig.setAreaCallback(bind(&Circle::printArea, &circle));
    // func(fig);

    // cout << endl;
    // fig.setDisplayCallback(bind(&Triangle::show, &triangle));
    // fig.setAreaCallback(bind(&Triangle::showArea, &triangle));
    // func(fig);

    return 0;
}