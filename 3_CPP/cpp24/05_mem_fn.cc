#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::bind;
using std::cout;
using std::endl;
using std::for_each;
using std::function;
using std::mem_fn;
using std::remove_if;
using std::vector;

class Number {
   public:
    Number(size_t data = 0) : _data(data) {}

    void print() { cout << _data << "  "; }

    // 偶数
    bool isEven() const { return (0 == _data % 2); }

    // 质数
    bool isPrime() const {
        if (1 == _data) {
            return false;
        }

        for (size_t idx = 2; idx <= _data / 2; ++idx) {
            if (0 == _data % idx) {
                return false;
            }
        }
        return true;
    }

    ~Number() {}

   private:
    size_t _data;
};

void test0() {
    vector<Number> vec;
    for (size_t idx = 1; idx != 30; ++idx) {
        vec.push_back(Number(idx));
    }

    // 使用for_each打印
    // for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    // cout << endl;
    // 使用for_each打印

    using namespace std::placeholders;
    function<void(Number)> f = bind(&Number::print, _1);
    // for_each(vec.begin(), vec.end(), bind(&Number::print, _1));
    for_each(vec.begin(), vec.end(), f);
    cout << endl;

    // 删除所有的偶数
    vec.erase(remove_if(vec.begin(), vec.end(), mem_fn(&Number::isEven)),
              vec.end());
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;

    // 删除所有的质数
    vec.erase(remove_if(vec.begin(), vec.end(), mem_fn(&Number::isPrime)),
              vec.end());
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;
}

int main() {
    test0();
    return 0;
}