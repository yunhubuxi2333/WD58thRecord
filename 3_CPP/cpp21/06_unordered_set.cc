#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    // unordered_set的基本特征
    // 1、存放的是key类型，key值是唯一的，不能重复
    // 2、key值是没有顺序的
    // 3、底层使用的是哈希
    unordered_set<int> number = {1, 3, 9, 8, 6, 4, 3, 3, 2, 1};
    display(number);
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
