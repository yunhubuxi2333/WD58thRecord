#include <functional>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::function;
using std::string;

void test0() {
    int number = 100;

    function<void(int)> f = [&number](int value) -> void {
        ++number;
        cout << "number = " << number << endl;
        cout << "value = " << value << endl;
    };
    f(10);

    cout << endl;
    function<void(string&, int&)> f2 = 
    [number](string& name, int& value) {
        cout << "number = " << number << endl;
        name = "wangdao";
        cout << "name = " << name << endl;
        cout << "value = " << value << endl;
    };
    string nn = "hello";
    int tt = 200;
    f2(nn, tt);
}

int main() {
    test0();
    return 0;
}