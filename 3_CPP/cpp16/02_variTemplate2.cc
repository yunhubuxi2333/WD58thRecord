#include <iostream>
using std::cout;
using std::endl;

double add() { return 0; }

double add(int x) { return x; }

template <class T1, class T2, class... Args>
double add(T1 x, T2 y, Args... args) {
    return x + y + add(args...);
}

void test0() { cout << add(2, 6.7, 4, 9.2, 2.2,2) << endl; }

int main() {
    test0();
    return 0;
}