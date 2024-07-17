#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0() {
    vector<int> nums;

    cout << endl;
    cout << sizeof(nums) << endl;  // 24,元素没有占据vector的空间

    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    // vector<int> nums2(5, 8);
    // cout << "nums'size: " << nums2.size() << endl;
    // cout << "nums'capacity: " << nums2.capacity() << endl;

    nums.push_back(1);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(2);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(3);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(4);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(5);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(6);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(7);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(8);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(9);
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    cout << endl;
    cout << sizeof(nums) << endl;  // 24,元素没有占据vector的空间
}

int main() {
    test0();
    return 0;
}