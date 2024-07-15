#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::weak_ptr;

class Child;

class Parent {
   public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << "~Parent()" << endl; }
    // 只需要Child类型的指针，不需要类的完整定义
    weak_ptr<Child> _spChild;
};

class Child {
   public:
    Child() { cout << "child()" << endl; }
    ~Child() { cout << "~child()" << endl; }
    shared_ptr<Parent> _spParent;
};

void test0() {
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childptr(new Child());
    cout << parentPtr.use_count() << endl;
    cout << childptr.use_count() << endl;

    parentPtr->_spChild = childptr;
    childptr->_spParent = parentPtr;
}

int main() {
    test0();
    return 0;
}