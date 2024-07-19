#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

void test() {
    // 遍历容器中的元素
    vector<int> vec = {1, 5, 9, 7, 4};
    ostream_iterator<int> osi(cout, " ");
    copy(vec.begin(), vec.end(), osi);
    cout << endl;
}

int main() {
    test();
    return 0;
}