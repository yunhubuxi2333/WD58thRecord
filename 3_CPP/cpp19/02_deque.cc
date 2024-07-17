#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;

// display的模板
template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    deque<int> number = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    display(number);
    std::deque<int>::iterator it = number.begin();
    cout << endl << "在deque的尾部进行插入与删除" << endl;
    it += 2;
    cout << "*it = " << *it << endl;
    number.push_back(100);
    number.push_back(200);
    display(number);
    cout << "*it = " << *it << endl;
    number.pop_back();
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl << "在deque的头部进行插入与删除" << endl;
    it = number.begin();
    it += 2;
    display(number);
    cout << "*it = " << *it << endl;
    //++it;
    number.insert(number.begin() + 3, 1, 99999);
    display(number);
    cout << "*it = " << *it << endl;
    number.pop_front();
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl << "在deque的任意位置进行插入" << endl;
    it = number.begin();
    it += 2;
    cout << "*it = " << *it << endl;
    number.insert(it, 30);
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    number.insert(it, 3, 20);
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    deque<int> vec = {11, 33, 66, 44, 22};
    number.insert(it, vec.begin(), vec.end());
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl;
    number.insert(it, {100, 300, 500});
    display(number);
    cout << "*it = " << *it << endl;

    cout << endl << "deque的元素的清空" << endl;
    number.clear();
    number.shrink_to_fit();  // 回收多余的空间
    cout << "size() = " << number.size() << endl;
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
