#include <iostream>
using namespace std;

void test0() {
    int a;
    cin >> a;
    int count = 0;
    while (a) {
        ++count;
        a = (a - 1) & a;
    }
    cout << count << endl;
}

int main() {
    test0();
    return 0;
}