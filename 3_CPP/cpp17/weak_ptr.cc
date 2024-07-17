#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::weak_ptr;

void test0() {
    weak_ptr<int> wp;
    shared_ptr<int> sp(new int(5));

    weak_ptr<int> wp2(sp);
    wp = sp;
    cout << wp.use_count() << endl;

    // weak_ptr不能直接访问其指向的资源
    // *wp;

    if (sp) {
        cout << "hello" << endl;
    }
}

weak_ptr<int> wp2;

void test1() {
    weak_ptr<int> wp;
    shared_ptr<int> sp(new int(5));
    wp = sp;
    wp2 = sp;

    shared_ptr<int> sp2 = wp.lock();
    cout << wp.use_count() << endl;

    if (sp2) {
        cout << "提升成功" << endl;
        cout << *sp2 << endl;
    } else {
        cout << "提升失败，托管的空间不存在" << endl;
    }

    // wp关联的空间还在，返回false
    bool flag = wp.expired();
    if (flag) {
        cout << "托管的空间已经被销毁" << endl;
    } else {
        cout << "托管的空间还在" << endl;
    }
}

int main() {
    test1();
    return 0;
}