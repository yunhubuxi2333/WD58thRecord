#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::for_each;
using std::ostream_iterator;
using std::vector;

void func(int& value) {
    ++value;
    cout << value << "  ";
}
void test0() {
    vector<int> vec = {1, 4, 9, 7, 2};
    for_each(vec.begin(), vec.end(), [](int& value) {
        ++value;
        cout << value << "  ";
    });
    cout << endl;

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));
}

int main() {
    test0();
    return 0;
}