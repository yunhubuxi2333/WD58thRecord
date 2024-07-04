#include <iostream>
using std::cout;
using std::endl;
using std::istream;
class Complex {
   public:
    Complex operator++(int) {
        cout << "Complex的后置++" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }
    friend istream& operator>>(istream& is, Complex& rhs);

   private:
    int _real;
    int _image;
};

istream& operator>>(istream& is, Complex& rhs) {
    cout << "请输入实部" << endl;
    is >> rhs._real;
    cout << "请输入虚部" << endl;
    is >> rhs._image;
    return is;
}

void test0() {
    int a = 10;
    ++a;
    a++;
}

int main() {
    test0();
    return 0;
}