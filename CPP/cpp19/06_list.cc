#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

struct CompareList {
    bool operator()(const int& lhs, const int& rhs) const {
        cout << "struct CompareList" << endl;
        return lhs < rhs;
    }
};

void test() {
    list<int> number = {1, 3, 5, 7, 5, 5, 3, 5, 3, 8};
    display(number);

    cout << endl << "list的unique函数" << endl;
    number.unique();
    display(number);
}
int main(int argc, char argv[]) {
    test();
    return 0;
}