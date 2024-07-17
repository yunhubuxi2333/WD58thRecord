#include <unistd.h>

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

void test0() {
    for (int i = 0; i < 1024; i++) {
        cout << 'a';
    }

    sleep(2);

    cout.flush();

    sleep(2);
}

void test1() {
    // cerr不进行缓冲
    sleep(2);
    cerr << 1;
    cerr << 3;
    sleep(2);
    cout << endl;
}
int main() {
    test1();

    return 0;
}