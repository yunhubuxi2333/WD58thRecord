#include <fstream>
#include <iostream>
#include <limits>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ofstream;
using std::ostream;

void inputInt(istream& is, int& num) {
    while (is >> num, !is.eof()) {
        if (is.bad()) {
            cerr << "istream has broken!" << endl;
            return;
        } else if (is.fail()) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "请输入一个int型数据" << endl;
        } else {
            break;
        }
    }
}

class Complex {
   public:
    Complex(int real, int image) : _real(real), _image(image) {}

    void print() const { cout << _real << " + " << _image << "i" << endl; }

    Complex& operator+=(const Complex& rhs) {
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }

    // 前置++
    Complex& operator++() {
        cout << "Complex的前置++" << endl;
        ++_real;
        ++_image;
        return *this;
    }

    // 后置++
    Complex operator++(int) {
        cout << "Complex的后置++" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }

    // 成员函数<<
    ostream& operator<<(ostream& os) { os << _real << " + " << _image << "i"; }

    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend istream& operator>>(istream& is, Complex& rhs);
    friend ostream& operator<<(ostream& os, const Complex& rhs);

   private:
    int _real;
    int _image;
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs._real + rhs._real, lhs._image + rhs._image);
}

ostream& operator<<(ostream& os, const Complex& rhs) {
    os << rhs._real << " + " << rhs._image << "i";
    return os;
}

istream& operator>>(istream& is, Complex& rhs) {
    cout << "请输入实部" << endl;
    // is >> rhs._real;
    inputInt(is, rhs._real);
    cout << "请输入虚部" << endl;
    // is >> rhs._image;
    inputInt(is, rhs._image);

    return is;
}

void test0() {
    // int a = 10;
    // ++a;
    // a++;

    Complex cx1(1, 2);
    cout << cx1 << endl;

    // 成员函数形式进行重载，只能实现这样的效果
    // 因为this指针必然会成为成员函数的第一个参数
    // 所以使用时只能把自定义类型对象当做第一个操作数
    cx1 << cout << endl;
    cx1.operator<<(cout) << endl;  // 本质
}

void test1() {
    Complex cx1(3, 6);
    cout << cx1 << endl;
    // operator<<(cout, cx1) << endl;  // 本质

    ofstream ofs("res.txt");
    ofs << cx1 << endl;
    // operator<<(ofs, cx1) << endl;  // 本质
}

void test2() {
    Complex cx1(7, 5);
    cin >> cx1;
    // operator>>(cin, cx1);  // 本质

    cout << cx1 << endl;
}

int main() {
    // test0();
    // test1();
    test2();

    return 0;
}