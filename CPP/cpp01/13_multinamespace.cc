#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 100;
void print() { cout << "print()" << endl; }
}  // namespace wd

namespace wd {
int num2 = 1000;
// 上下两次定义wd命名空间，会被编译器认为是同一个命名空间
// 所以这里需要注意避免与上面的num重名
}  // namespace wd

void test0() {
    using namespace wd;
    cout << num << endl;
    cout << num2 << endl;
}
int main() {
    test0();
    return 0;
}