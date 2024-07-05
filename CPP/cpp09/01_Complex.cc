#include <iostream>

using std::cout;
using std::endl;

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }

    Complex& operator+=(const Complex& rhs) {
        _real += rhs._real;
        _image += rhs._image;
    }

    // 前置++
    Complex& operator++() {
        cout << "Complex的前置++" << endl;
        ++_real;
        ++_image;
        return *this;
    }

    // 后置++不需要引用
    // 后置++运算符重载函数的参数列表中加上一个int
    // 以示与前置++运算符重载函数区分
    Complex operator++(int) {
        cout << "Complex的后置++" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }

    friend Complex operator+(const Complex& lhs, const Complex& rhs);

   private:
    int _real;
    int _image;
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs._real + rhs._real, lhs._image + rhs._image);
}

void test0() {
    int a = 10;
    ++a;  // 表达式返回a+1,副作用就是a自增
    a++;  // 表达式返回a，副作用是a自增

    Complex cx1(1, 2);
    ++cx1;
    cx1.print();

    cx1++;
    cx1.print();
}

int main() {
    test0();
    return 0;
}