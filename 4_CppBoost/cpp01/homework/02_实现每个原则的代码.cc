#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Rectangle {
   public:
    double area() const;
};

class RectangleGUI : public Rectangle {
   public:
    void draw() const;
};

class GUI {};

class GeometryApp {
    void CalculateArea(const Rectangle& rect) const {
        cout << rect.area() << endl;
    }
};

class GraphicalApp {
    void drawShape(const RectangleGUI& rectgui) const { rectgui.draw(); }
};