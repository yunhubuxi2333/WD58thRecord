#include <iostream>
#include <set>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::multiset;
using std::pair;
using std::vector;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    // multiset的基本特征
    // 1、存放的是key类型，key值是不唯一的，可以重复
    // 2、默认会按照key值进行升序排列
    // 3、multiset的底层实现使用的是红黑树
    multiset<int> number = {1, 3, 4, 3, 5, 9, 8, 5, 7};
    display(number);

    cout << endl << "multiset的查找操作" << endl;
    size_t cnt = number.count(5);
    cout << "cnt(5) = " << cnt << endl;

    cout << endl;
    /* multiset<int>::iterator it = number.find(7); */
    auto it = number.find(7);
    if (it != number.end()) {
        cout << "查找成功 " << *it << endl;
    } else {
        cout << "查找失败，该元素不在multiset中" << endl;
    }

    cout << endl << "multiset的bound操作" << endl;
    auto it2 = number.lower_bound(3);
    auto it3 = number.upper_bound(3);
    cout << "*it2 = " << *it2 << endl;
    cout << "*it3 = " << *it3 << endl;
    while (it2 != it3) {
        cout << *it2 << "  ";
        ++it2;
    }
    cout << endl;
    // pair<multiset<int>::iterator, multiset<int>::iterator> ret =
    //     number.equal_range(3);
    auto ret = number.equal_range(3);
    while (ret.first != ret.second) {
        cout << *ret.first << "  ";
        ++ret.first;
    }
    cout << endl;

    cout << endl << "multiset的insert操作" << endl;
    number.insert(20);
    display(number);

    cout << endl;
    vector<int> vec = {11, 44, 77, 3, 5, 10};
    number.insert(vec.begin(), vec.end());
    display(number);

    cout << endl;
    number.insert({6, 13, 45, 89, 12});
    display(number);

    cout << endl << "multiset的删除操作" << endl;
    it = number.begin();
    /* it += 3;//error */
    ++it;
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.erase(it);
    display(number);

    /* cout << endl << endl << "multiset的下标" << endl; */
    /* cout << "number[1] = " << number[1] << endl; */

    cout << endl << endl << "修改操作" << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    // *it = 500;  // error   // read-only
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}