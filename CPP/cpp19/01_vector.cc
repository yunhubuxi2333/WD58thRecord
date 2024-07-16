#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// display的模板
template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

void test() {
    cout << "sizeof(vector<int>) = " << sizeof(vector<int>) << endl;
    cout << "sizeof(vector<long>) = " << sizeof(vector<long>) << endl;

    vector<int> number = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    display(number);
    cout << "size = " << number.size() << endl;
    cout << "capacity = " << number.capacity() << endl;

    cout << endl << "在vector的尾部进行插入与删除" << endl;
    number.push_back(100);
    number.push_back(200);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    number.pop_back();
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;

    // 为何vector不提供在头部进行插入与删除的操作呢？
    // 因为vector是一端开口的，如果在头部插入一个元素或者删除一个元素
    // 后面的元素都会进行移动，导致效率比较低，O（N）

    // 如何获取vector中的第一个元素的首地址？
    &number;           // error
    &number[0];        // ok
    &*number.begin();  // ok

    cout << endl << "在vector的任意位置进行插入" << endl;
    std::vector<int>::iterator it = number.begin();
    it += 2;

    cout << "*it = " << *it << endl;
    number.insert(it, 30);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl;
    // 对于vector的insert操作而言，插入元素的个数是不确定的
    // 有可能在插入过程中,底层已经发生了扩容，而迭代器还指向旧的空间
    // 但是已经在新的空间上进行操作了，所以这个时候就会出现问题
    // 这种情况就称之为迭代器失效了
    //
    // 解决方案：每次在使用迭代器的时候，将迭代器重新置位
    it = number.begin();
    it += 2;
    cout << "*it = " << *it << endl;
    number.insert(it, 10, 20);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl;
    vector<int> vec = {11, 33, 66, 44, 22};
    it = number.begin();  // 重新置位
    it += 2;
    cout << "*it = " << *it << endl;
    number.insert(it, vec.begin(), vec.end());
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl;
    it = number.begin();  // 重新置位
    it += 2;
    cout << "*it = " << *it << endl;
    number.insert(it, {100, 300, 500});
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
    cout << "*it = " << *it << endl;

    cout << endl << "vector的元素的清空" << endl;
    number.clear();
    number.shrink_to_fit();  // 回收多余的空间
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
