#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::string;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test() {
    // map的基本特征
    // 1、存放的是key-value类型，key值是唯一的，不能重复
    //      但是value值是可以重复，也可以不重复
    // 2、默认情况下，会按照key值进行升序排列
    // 3、map的底层也是使用红黑树
    map<int, string> number = {
        /* map<int, string, std::greater<int>> number = { */
        pair<int, string>(4, "wangdao"),
        pair<int, string>(5, "wangdao"),

        make_pair(2, "wuhan"),
        make_pair(1, "beijing"),

        {7, "nanjing"},
        {7, "test"},
    };
    display(number);

    cout << endl << "map的查找" << endl;
    size_t cnt = number.count(5);
    cout << "cnt = " << cnt << endl;

    map<int, string>::iterator it = number.find(5);
    if (it != number.end()) {
        cout << "该元素是存在的 " << endl;
        cout << it->first << "  " << it->second << endl;
    } else {
        cout << "该元素不存在" << endl;
    }

    cout << endl << "map的insert操作" << endl;
    pair<map<int, string>::iterator, bool> ret = number.insert({8, "test"});
    if (ret.second) {
        cout << "插入成功 " << ret.first->first << "  " << ret.first->second
             << endl;
    } else {
        cout << "插入失败了，该元素存在map中" << endl;
    }
    display(number);
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}