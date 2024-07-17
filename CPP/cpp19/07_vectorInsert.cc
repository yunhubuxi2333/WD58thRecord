#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    vector<int> number = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;

    cout << endl << "在vector的尾部进行插入与删除" << endl;
    number.push_back(100);
    number.push_back(200);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;

    cout << endl << "在vector的任意位置进行插入与删除" << endl;
    auto it = number.begin();
    it += 2;
    cout << "*it = " << *it << endl;
    number.insert(it, 30);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl;
    it = number.begin();
    it += 2;
    cout << "*it = " << *it << endl;
    // size() = m = 13,capacity = n = 20,插入元素的个数t
    // 1、t < n - m = 7; 此时并不会发生扩容
    // 2、n - m < t < m; 此时会按照 2 * m 进行扩容
    // 3、n - m < t, t < m; 此时会按照 t + m 进行扩容
    // 4、n - m < t, t > n; 此时会按照 t + m 进行扩容
    number.insert(it, 200, 20);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl;
    vector<int> vec = {11, 33, 66, 44, 22};
    it = number.begin();
    it += 2;
    number.insert(it, vec.begin(), vec.end());
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;
}

int main() {
    test();
    return 0;
}