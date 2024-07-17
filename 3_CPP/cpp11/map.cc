#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::set;
using std::string;

void test0() {
    map<int, string> nums;

    map<int, string> nums2{{1, "beijing"},
                           {2, "shanghai"},
                           {3, "wuhan"},
                           pair<int, string>(5, "hangzhou"),
                           pair<int, string>(3, "dalian"),
                           make_pair(1, "guangzhou"),
                           make_pair(9, "shenzhen"),
                           make_pair(6, "wuhan")};

    for (auto& ele : nums2) {
        cout << ele.first << " " << ele.second << endl;
    }

    cout << endl;
    auto it = nums2.begin();
    // map<int, string>::iterator it = nums2.begin();
    for (; it != nums2.end(); ++it) {
        // cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }
}

// map的查找操作
void test1() {
    map<int, string> nums{{1, "beijing"},
                          {2, "shanghai"},
                          {3, "wuhan"},
                          pair<int, string>(5, "hangzhou"),
                          make_pair(7, "guangzhou")};

    size_t cnt = nums.count(6);
    cout << cnt << endl;

    map<int, string>::iterator it = nums.find(3);
    if (it != nums.end()) {
        cout << "该元素存在 : " << it->first << " " << it->second << endl;
    } else {
        cout << "该元素不存在" << endl;
    }
}

// map 的插入操作
void test2() {
    map<int, string> nums{{1, "beijing"},
                          {2, "shanghai"},
                          {3, "wuhan"},
                          pair<int, string>(5, "hangzhou"),
                          make_pair(7, "guangzhou")};

    pair<map<int, string>::iterator, bool> ret =
        nums.insert(pair<int, string>(8, "fuyang"));

    if (ret.second) {
        cout << "插入成功！！！" << endl;
        cout << ret.first->first << " " << ret.first->second << endl;
    } else {
        cout << "插入失败，该元素已存在！！！" << endl;
        cout << ret.first->first << " " << ret.first->second << endl;
    }

    cout << endl;

    nums.insert({{6, "qingdao"}, {9, "litang"}, {5, "taiyuan"}, {4, "wuhu"}});

    for (auto& ele : nums) {
        cout << ele.first << " " << ele.second << endl;
    }
}

int main() {
    test2();
    return 0;
}
