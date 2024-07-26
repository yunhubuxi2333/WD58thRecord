#include <math.h>

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

class Figure {
   public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
   public:
    Rectangle(double length = 0, double width = 0)
        : _length(length), _width(width) {
        cout << "Rectangle(double = 0,double = 0)" << endl;
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

    double area() const override { return 3.14 * _radius * _radius; }

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

// 简单工厂模式（静态工厂模式）：工厂会根据产品的名字生产出对应的产品
// 一个工厂可以生产出多种产品
//
// 优点：只需要知道产品的名字就可以生产出对应的产品
// 缺点：(如果从设计原则来看，会违反哪些设计原则)
// 1、违反了单一职责原则
// 2、违反了开放闭合原则
// 3、违反了依赖倒置原则

class Factory {
   public:
    static Figure* create(const string& name) {
        if (name == "rectangle") {
            // 可以通过配置文件进行获取
            // 配置文件的形式.txt、xml、bat、yang
            // 读取配置文件，然后从配置文件中获取所需的数据
            Rectangle* prec = new Rectangle(10, 20);
            return prec;
        } else if (name == "circle") {
            Circle* pcir = new Circle(10);
            return pcir;
        } else if (name == "triangle") {
            Triangle* ptri = new Triangle(3, 4, 5);
            return ptri;
        } else if (name == "xxxx") {
        } else {
            return nullptr;
        }
    }
};

int main() {
    unique_ptr<Figure> prec(Factory::create("rectangle"));
    unique_ptr<Figure> pcir(Factory::create("circle"));
    unique_ptr<Figure> ptri(Factory::create("triangle"));

    func(prec.get());
    func(pcir.get());
    func(ptri.get());

    return 0;
}