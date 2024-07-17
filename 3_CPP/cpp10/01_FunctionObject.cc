#include <iostream>
using std::cout;
using std::endl;

class FunctionObject {
   public:
    // 对函数调用符———— （）进行了重载
    // 第一个括号是和operator连在一起作为函数名
    // 第二个括号是参数列表，只不过此时定义的是一个无参的成员函数

    void operator()() {
        ++_cnt;
        cout << "oprator()函数一" << endl;
    }

    // 函数调用运算符比较特殊
    // 其操作数个数可以为任意个数（this指针必须有）
    int operator()(int x) {
        ++_cnt;
        cout << "operator()函数二" << endl;
        return x;
    }

    double operator()(double x, int y) {
        ++_cnt;
        cout << "operator()函数三" << endl;
        return x + y;
    }

    int getCount() const { return _cnt; }

   private:
    int _cnt = 0;
};

int cnt = 0;

void func() {
    ++cnt;
    cout << "hello" << endl;
}

int func(int x) {
    ++cnt;
    return x;
}

double func(double x, int y) {
    ++cnt;
    return x + y;
}

void test0() {
    FunctionObject fo;

    // fo对象可以作为函数对象使用
    fo();
    // fo.operator()();  // 本质

    cout << fo(5) << endl;
    // cout << fo.operator()(5) << endl;  // 本质

    cout << fo(3.5, 7) << endl;
    // cout << fo.operator()(3.5, 7) << endl;  // 本质

    // 对于函数对象，想要记录调用的次数
    // 可以通过数据成员的方式进行记录
    // 比较安全
    cout << fo.getCount() << endl;

    //_cnt是私有成员，无法直接访问
    // cout << fo._cnt << endl;

    // 对于普通函数，记录被调用的次数
    // 只能通过全局变量
    // 不够安全
    func();
    func(2);
    func(6.6, 6);
    cout << cnt << endl;
    cnt = 0;
    cout << cnt << endl;
}

int main() {
    test0();
    return 0;
}
