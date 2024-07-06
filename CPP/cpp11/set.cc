#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

void test0() {
    set<int> nums;
    set<int> nums2{5, 4, 3, 2, 1};
    set<int> nums3(nums2);
    set<int> nums4(nums2.begin(), --nums2.end());

    for (auto& nu : nums2) {
        cout << nu << " ";
    }

    cout << endl;

    cout << nums2.count(3) << endl;

    set<int>::iterator it = nums2.find(50);
    // auto it = nums2.find(50);
    if (it != nums2.end()) {
        cout << "该元素存在" << *it << endl;
    } else {
        cout << "该元素不存在" << endl;
    }
}

// void test1(){
//     pair<int,string>
// }

void test2() {
    set<int> nums{1, 4, 8, 7, 2, 1, 3, 7};
    for (auto& nu : nums) {
        cout << nu << " ";
    }
    cout << endl;

    // pair<set<int>::iterator, bool> ret = nums.insert(2);
    auto ret = nums.insert(5);
    if (ret.second) {
        cout << "插入成功:" << *ret.first << endl;
    } else {
        cout << "插入失败,该元素已存在:" << *(ret.first) << endl;
    }

    for (auto& nu : nums) {
        cout << nu << " ";
    }
    cout << endl;

    set<int> nums2{7, 8, 9, 3, 20, 35};
    nums.insert(nums2.begin(), nums2.end());

    for (auto& nu : nums) {
        cout << nu << " ";
    }
    cout << endl;

    nums.insert({4, 40, 26});
    for (auto& nu : nums) {
        cout << nu << " ";
    }
    cout << endl;
}

int main() {
    test2();
    return 0;
}