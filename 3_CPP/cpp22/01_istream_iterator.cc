#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

void test() {
    vector<int> vec;
    vec.reserve(10);

    istream_iterator<int> isi(std::cin);
    copy(isi, istream_iterator<int>(), vec.begin());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "   "));

    cout << endl;
}

void test0() {
    vector<int> vec;

    istream_iterator<int> isi(std::cin);
    // back_inserter的底层会调用push_back
    copy(isi, istream_iterator<int>(), std::back_inserter(vec));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "   "));

    cout << endl;
}

int main() {
    test0();
    return 0;
}