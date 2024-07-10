#include <math.h>
#include <string.h>

#include <iostream>
using namespace std;

class Point {
   public:
    Point(int x, int y) : _x(x), _y(y) {}
    friend class Line;

   private:
    float _x;
    float _y;
};

class Line {
   public:
    Line(const Point& lhs, const Point& rhs) : _start(lhs), _end(rhs) {}

    Line(int x1, int y1, int x2, int y2) : _start(x1, y1), _end(x2, y2) {}

    float distance() const {
        return sqrt(pow(_start._x - _end._x, 2) + pow(_start._y - _end._y, 2));
    }

   private:
    Point _start;
    Point _end;
};

class Color {
   public:
    Color(const char* color) : _color(new char[strlen(color) + 1]()) {
        strcpy(_color, color);
    }

    ~Color() {
        if (_color) {
            delete[] _color;
        }
    }

    Color(const Color& rhs) : _color(new char[strlen(rhs._color) + 1]()) {
        strcpy(_color, rhs._color);
    }

    Color& operator=(const Color& rhs) {
        if (this != &rhs) {
            delete[] _color;
            _color = new char[strlen(rhs._color) + 1]();
            strcpy(_color, rhs._color);
        }

        return *this;
    }

    void printcolor() const { cout << "颜 色 : " << _color << endl; }

   private:
    char* _color;
};

class Triangle : public Line, public Color {
   public:
    Triangle(const Point& p1, const Point& p2, const char* color, float height)
        : Line(p1, p2), Color(color), _height(height) {}

    Triangle(int x1, int y1, int x2, int y2, const char* color, float height)
        : Line(x1, y1, x2, y2), Color(color), _height(height) {}

    float perimeter() const {
        float x = distance();
        float z = sqrt(x * x + _height * _height);
        return x + _height + z;
    }

    float getArea() const {
        float x = distance();
        return x * _height / 2;
    }

    void show() const {
        printcolor();
        cout << "周 长 = " << perimeter() << endl;
        cout << "面 积 = " << getArea() << endl;
    }

   private:
    float _height;
};

void test0() {
    Triangle t1(0, 0, 3, 0, "blue", 4);
    t1.show();

    cout << endl;
    Point p1(0, 0);
    Point p2(5, 0);
    Color("Orange");
    Triangle t2(p1, p2, "Orange", 12);
    t2.show();
}

int main() {
    test0();
    return 0;
}