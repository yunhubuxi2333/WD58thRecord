#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::multimap;
using std::pair;
using std::string;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test() {
    // multimap的基本特征
    // 1、存放的是key-value类型，key值是不唯一的，可以重复
    //    value值是可以重复，也可以不重复
    // 2、默认情况下，会按照key值进行升序排列
    // 3、multimap的底层也是使用红黑树
    multimap<int, string> number = {
        /* multimap<int, string, std::greater<int>> number = { */
        pair<int, string>(4, "wangdao"),
        pair<int, string>(5, "wangdao"),

        make_pair(2, "wuhan"),
        make_pair(1, "beijing"),

        {7, "nanjing"},
        {7, "test"},
    };
    display(number);

    cout << endl << "multimap的查找" << endl;
    size_t cnt = number.count(5);
    cout << "cnt = " << cnt << endl;

    multimap<int, string>::iterator it = number.find(5);
    if (it != number.end()) {
        cout << "该元素是存在的 " << endl;
        cout << it->first << "  " << it->second << endl;
    } else {
        cout << "该元素不存在" << endl;
    }

    cout << endl << "multimap的insert操作" << endl;
    number.insert({8, "test"});
    display(number);

    cout << endl << "multimap的下标操作（不支持）" << endl;
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}