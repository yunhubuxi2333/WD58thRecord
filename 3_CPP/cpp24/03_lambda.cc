#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

vector<function<void(const string&)>> vec;

void test0() {
    int num = 100;
    string name = "wangdao";
    vec.push_back([num, name](const string& value) {
        cout << "num = " << num << endl;
        cout << "name = " << name << endl;
        cout << "value = " << value << endl;
    });
    // for (auto func : vec) {
    //     func("wuhan");
    // }
}

void test2() {
    for (auto func : vec) {
        func("wuhan");
    }
}

int main() {
    test0();
    test2();
    return 0;
}