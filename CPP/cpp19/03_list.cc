#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

// display的模板
template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    list<int> number = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    display(number);

    cout << endl << "在list的尾部进行插入与删除" << endl;
    number.push_back(100);
    number.push_back(200);
    display(number);
    number.pop_back();
    display(number);

    cout << endl << "在list的头部进行插入与删除" << endl;
    number.push_front(111);
    number.push_front(222);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "在list的任意位置进行插入" << endl;
    auto it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.insert(it, 30);
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    number.insert(it, 3, 20);
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    list<int> vec = {11, 33, 66, 44, 22};
    number.insert(it, vec.begin(), vec.end());
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    number.insert(it, {100, 300, 500});
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl << "list的元素的清空" << endl;
    number.clear();
    cout << "size() = " << number.size() << endl;
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
