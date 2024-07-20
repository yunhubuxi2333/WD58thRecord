#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>

using std::back_insert_iterator;
using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::front_insert_iterator;
using std::front_inserter;
using std::insert_iterator;
using std::inserter;
using std::list;
using std::ostream_iterator;
using std::set;
using std::vector;

void test0() {
    vector<int> vec = {1, 3, 7, 9, 5};
    list<int> lstNum = {11, 44, 66, 22};
    // 将list中的元素插入到vector尾部
    copy(lstNum.begin(), lstNum.end(), back_insert_iterator<vector<int>>(vec));
    cout << "vector = ";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    // 将vector中的元素插入到list头部
    copy(vec.begin(), vec.end(), front_inserter(lstNum));
    cout << "list = ";
    copy(lstNum.begin(), lstNum.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    cout << endl;
    set<int> setNum = {1, 7, 44, 12, 34, 67};
    cout << "set = ";
    
    // 将vector的元素插入到set中
    auto it = setNum.begin();
    copy(vec.begin(), vec.end(), inserter(setNum, it));
    cout << "set = ";
    copy(setNum.begin(), setNum.end(), ostream_iterator<int>(cout, "  "));

    cout << endl;
}

int main() {
    test0();
    return 0;
}