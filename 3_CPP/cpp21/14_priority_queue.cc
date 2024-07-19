#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test0() {
    vector<int> vec = {1, 3, 7, 9, 5, 3};
    // 新的初始化方式
    // priority_queue<int> pque(vec.begin(),vec.end());
    priority_queue<int> pque(vec.begin(), vec.end());

    while (!pque.empty()) {
        cout << pque.top() << "  ";
        pque.pop();
    }
    cout << endl;
}

void test() {
    vector<int> vec = {1, 3, 7, 9, 5, 3};
    priority_queue<int> pque;
    for (size_t idx = 0; idx != vec.size(); ++idx) {
        pque.push(vec[idx]);
        cout << "优先级最高的元素是" << pque.top() << endl;
    }

    while (!pque.empty()) {
        cout << pque.top() << "  ";
        pque.pop();
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}