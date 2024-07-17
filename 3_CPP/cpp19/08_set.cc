#include <iostream>
#include <set>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::vector;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test0() {
    // set的基本特征
    // 1、存放的是key类型，key值是唯一的，不能重复
    // 2、默认会按照key值进行升序排列
    // 3、set的底层实现使用的是红黑树
    set<int> number = {1, 3, 4, 3, 5, 9, 8, 5, 7};
    display(number);

    cout << endl << "set的查找操作" << endl;
    size_t cnt = number.count(5);
    cout << "cnt = " << cnt << endl;

    cout << endl;
    auto it = number.find(7);
    if (it != number.end()) {
        cout << "查找成功 " << *it << endl;
    } else {
        cout << "查找失败，该元素不在set中" << endl;
    }

    cout << endl << "set的insert操作" << endl;
    pair<set<int>::iterator, bool> ret = number.insert(20);
    if (ret.second) {
        cout << "插入成功" << *ret.first << endl;
    } else {
        cout << "插入失败,该元素存在set中" << endl;
    }
    display(number);

    cout << endl;
    vector<int> vec = {11, 44, 77, 3, 5, 10};
    number.insert(vec.begin(), vec.end());
    display(number);

    cout << endl;
    number.insert({6, 13, 45, 89, 12});
    display(number);

    cout << endl << "set的删除操作" << endl;
    it = number.begin();
    ++it;
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.erase(it);
    display(number);

    cout << endl << endl << "修改操作" << endl;
    it = number.begin();
    ++it;
    ++it;
    //*it = 500;//read-only
    cout<<"*it = "<<*it<<endl;
}

int main() {
    test0();
    return 0;
}
