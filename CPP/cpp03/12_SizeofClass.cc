#include <iostream>
using std::cout;
using std::endl;

/* #pragma pack(4) */

class A {           // 16
    int _num;       // 4
    double _price;  // 8
};

class B {        // 12
    int _num;    // 4
    int _price;  // 4
    int _b2;     // 4
};

class C {        // 16
    int _c1;     // 4
    int _c2;     // 4
    double _c3;  // 8
};

class D {        // 24
    int _d1;     // 4
    double _d2;  // 8
    int _d3;     // 4
};

class E {            // 8 + 20 + 4 + 8 = 40
    double _e;       // 8
    char _eArr[20];  // 20
    int _e2;         // 4
    double _e1;      // 8
};

class F {            // 20
    char _fArr[20];  // 20
};

class G {            // 20 + 4 + 8 = 32
    char _gArr[20];  // 20
    int _g1;         // 4
    double _g2;      // 8
};

// 空类
class H {};  // 1

void test1() {
    cout << sizeof(H) << endl;
    H h1;
    H h2;
    cout << &h1 << endl;
    cout << &h2 << endl;
}

void test0() {
    cout << "sizeof(A) = " << sizeof(A) << endl;  // 16
    cout << "sizeof(B) = " << sizeof(B) << endl;  // 8
    cout << "sizeof(C) = " << sizeof(C) << endl;  //
    cout << "sizeof(D) = " << sizeof(D) << endl;  //
    cout << "sizeof(E) = " << sizeof(E) << endl;  //
    cout << "sizeof(F) = " << sizeof(F) << endl;  //
    cout << "sizeof(G) = " << sizeof(G) << endl;  //
}

int main(void) {
    test0();
    test1();
    return 0;
}