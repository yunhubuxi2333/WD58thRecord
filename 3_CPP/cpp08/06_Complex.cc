#include <iostream>
using std::cout;
using std::endl;

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }

    friend Complex operator+(const Complex& lhs, const Complex& rhs);

   private:
    int _real;
    int _image;
};

// 运算符重载的第一种方式————友元函数的方式
// 定义一个普通函数operator+
// 将这个函数声明为Complex类的友元函数
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs._real + rhs._real, lhs._image + rhs._image);
}

void test0() {
    int a = 1, b = 2;
    int c = a + b;
    cout << a << " + " << b << " = " << c << endl;

    Complex cx1(3, 7);
    Complex cx2(4, 5);
    cx1.print();
    cx2.print();

    Complex cx3 = cx1 + cx2;
    // Complex cx3 = operator+(cx1, cx2);   //本质
    cx3.print();
}

int main() {
    test0();
    return 0;
}