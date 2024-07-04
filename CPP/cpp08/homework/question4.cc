#include <iostream>
using namespace std;

class Base {
   public:
    Base(int x) : _ix(x - 2) {}
    friend int operator+(const Base& lhs, const Base& rhs);

   private:
    int _ix;
};

int operator+(const Base& lhs, const Base& rhs) { return lhs._ix + rhs._ix; }
void test0() {
    int i = 2;
    int j = 7;

    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
}
int main() {
    test0();
    return 0;
}