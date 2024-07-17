#include <iostream>
using std::cout;
using std::endl;

class B {
    int y;

   public:
    friend class A;
};

class A {
    int x;

   public:
    A(int a, B& r, int b) {
        x = a;
        r.y = b;
    }

    void Display(B&);
};

void A::Display(B& r) { cout << x << " " << r.y << endl; }

int main() {
    B Obj2;

    A Obj1(33, Obj2, 88);

    Obj1.Display(Obj2);
    return 0;
}
