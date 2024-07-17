#include <algorithm>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

template <class T>
T add(T t1, T t2) {
    return t1 + t2;
}

// 特化函数模板：两个存放int型元素的set融合
template <>
set<int> add<set<int>>(set<int> a, set<int> b) {
    set<int> result;
    set_union(a.begin(), a.end(), b.begin(), b.end(),
              std::inserter(result, result.begin()));
    return result;
}

void test0() {
    int i1 = 1, i2 = 2;
    double d1 = 1.1, d2 = 2.2;
    cout << "add(i1, i2) = " << add(i1, i2) << endl;
    cout << "add(d1, d2) = " << add(d1, d2) << endl;

    set<int> set1 = {1, 2, 3};
    set<int> set2 = {3, 4, 5};
    set<int> resultSet = add(set1, set2);

    cout << "resultSet:" << endl;
    for (auto ele : resultSet) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    test0();
    return 0;
}