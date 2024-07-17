#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test1() {
    vector<int> vec = {1, 3, 5, 5, 5, 5, 9, 7, 5, 5, 6};
    // 将所有元素等于5的全部删掉
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (5 == *it) {
            vec.erase(it);
        }
    }

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;
}
void test() {
    vector<int> vec = {1, 3, 5, 5, 5, 5, 9, 7, 5, 5, 6};
    // 将所有元素等于5的全部删掉
    for (auto it = vec.begin(); it != vec.end();) {
        if (5 == *it) {
            vec.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;
}
int main(int argc, char* argv[]) {
    test();
    return 0;
}