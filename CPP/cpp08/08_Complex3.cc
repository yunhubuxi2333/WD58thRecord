#include <iostream>
using std::cout;
using std::endl;

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }
    // 运算符重载的第三种方式————成员函数形式
    // 定义一个成员函数性质的运算符重载函数
    // 要注意第一个操作数实际上由this指针提供
    Complex operator+(const Complex& rhs) {
        return Complex(_real + rhs._real, _image + rhs._image);
    }

   private:
    int _real;
    int _image;
};

void test0() {
    int a = 1, b = 2;
    int c = a + b;
    cout << a << " + " << b << " = " << c << endl;

    Complex cx1(3, 7);
    Complex cx2(4, 5);
    cx1.print();
    cx2.print();

    // Complex cx3 = cx1 + cx2;
    Complex cx3 = cx1.operator+(cx2);  // 本质
    cx3.print();
}

int main() {
    test0();
    return 0;
}