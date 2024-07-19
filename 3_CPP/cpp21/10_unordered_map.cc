#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::unordered_map;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test() {
    // unordered_map的特征
    // 1、存放的是key-value类型，key值是唯一的，不能重复
    // value既可以重复，也可以不重复
    // 2、key值是没有顺序的
    // 3、底层使用的是哈希
    unordered_map<int, string> number = {
        // 构建pair的方式有三种
        {1, "wuhan"},
        {5, "beijing"},
        pair<int, string>(6, "shanghai"),
        pair<int, string>(6, "beijing"),
        make_pair(9, "hubei"),
        make_pair(4, "hubei"),
    };
    display(number);

    cout << endl << "下标操作" << endl;
    cout << "number[5] = " << number[5] << endl;
    cout << "number[10] = " << number[10] << endl;
    display(number);

    cout << endl;
    number[10] = "test";
    display(number);
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}