#include <iostream>

using namespace std;

class Complex() {
   public:
    Complex operator++(int) {
        cout << "Complex的后置++" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }

   private:
    int _real;
    int _image;
};

void test0() {
    int a = 10;
    ++a;
    a++;
}

int main() {
    test0();
    return 0;
}