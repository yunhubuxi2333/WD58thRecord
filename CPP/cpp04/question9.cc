#include <iostream>
using std::cout;
using std::endl;

class MyClass {
   public:
    MyClass(int i = 0) { cout << i << endl; }
    MyClass(const MyClass& x) { cout << 2 << endl; }
    MyClass& operator=(const MyClass& x) {
        cout << 3 << endl;
        return *this;
    }
    ~MyClass() { cout << 4 << endl; }
};
int main() {
    MyClass obj1(1), obj2(2);
    MyClass obj3 = obj1;
    return 0;
}
// 2203444
// 122444