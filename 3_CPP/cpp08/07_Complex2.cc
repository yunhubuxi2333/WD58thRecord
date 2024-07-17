#include <iostream>
using std::cout;
using std::endl;

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }

    int getReal() const { return _real; }
    int getImage() const { return _image; }

   private:
    int _real;
    int _image;
};

// 运算符重载的第二种方式————普通函数
// 在Complex类中提供一系列公有的get函数
// 在这个函数中调用这些get函数间接地获取到Complex的私有成员

// 很少使用这种方式，因为几乎完全破坏了对私有成员的隐藏性
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
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