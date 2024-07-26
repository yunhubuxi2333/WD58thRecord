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

// 工厂方法
// 缺点：工厂的数量会随着产品数量的增加，而发生急剧的变化
//
// 如果生产新的产品的时候，该模型的扩展性要好一些
// 优点：(如果从设计原则来看)
// 1、满足了单一职责原则
// 2、满足了开放闭合原则
// 3、满足了依赖倒置原则

class Factory {
   public:
    virtual Figure* create() = 0;
    virtual ~Factory() {}
};

class RectangleFactory : public Factory {
    virtual Figure* create() override {
        // 可以通过配置文件进行获取
        // 配置文件的形式.txt、xml、bat、yang
        // 读取配置文件，然后从配置文件中获取所需的数据
        Rectangle* prec = new Rectangle(10, 20);
        return prec;
    }
};

class CircleFactory : public Factory {
    virtual Figure* create() override {
        Circle* pcir = new Circle(10);
        return pcir;
    }
};

class TriangleFactory : public Factory {
    virtual Figure* create() override {
        Triangle* ptri = new Triangle(3, 4, 5);
        return ptri;
    }
};

int main() {
    unique_ptr<Factory> precFac(new RectangleFactory());
    unique_ptr<Figure> prec(precFac->create());

    unique_ptr<Factory> pcirFac(new CircleFactory());
    unique_ptr<Figure> pcir(pcirFac->create());

    unique_ptr<Factory> pTriFac(new TriangleFactory());
    unique_ptr<Figure> ptri(pTriFac->create());

    func(prec.get());
    func(pcir.get());
    func(ptri.get());

    return 0;
}