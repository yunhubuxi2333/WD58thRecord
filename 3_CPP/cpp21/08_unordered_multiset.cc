#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_multiset;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    // unordered_multiset的基本特征
    // 1、存放的是key类型，key值是不唯一的，可以重复
    // 2、key值是没有顺序的
    // 3、底层使用的是哈希
    unordered_multiset<int> number = {1, 3, 9, 8, 6, 4, 3, 3, 2, 1};
    display(number);
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}