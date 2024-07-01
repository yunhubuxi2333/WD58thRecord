#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0() {
    int arr[5] = {1, 2, 3, 4, 5};

    // <>中写vector要存放的元素的类型
    // 模板参数（类型参数）
    // vector 是类模板实现的
    // vector代表一类类
    // vector<int>可以代表一个特定的类

    // 1.无参构造
    vector<int> nums;
    cout << "is nums empty? " << nums.empty() << endl;

    // 2.传入一个参数
    // 10代表存放元素的个数
    vector<long> nums2(10);
    for (auto& ele : nums2) {
        cout << ele << " ";
    }
    cout << endl;

    // 3.存放了5个8
    vector<int> nums3(5, 8);
    for (auto& ele : nums3) {
        cout << ele << " ";
    }
    cout << endl;

    // 4.大括号形式
    // 大括号会匹配最合适的一种方式
    vector<int> nums4{1, 2, 3, 4, 5, 6, 7};
    for (auto& ele : nums4) {
        cout << ele << " ";
    }
    cout << endl;

    // 5.迭代器方式创建vector
    vector<int> nums5(nums4.begin(), nums4.end() - 3);
    for (auto& ele : nums5) {
        cout << ele << " ";
    }
    cout << endl;

    // 这样就没有复制arr的最后一个元素（左闭右开）
    vector<int> nums6(arr, arr + 4);
    for (auto& ele : nums6) {
        cout << ele << " ";
    }
    cout << endl;
}

// vector的常用操作
// vector可以动态开辟空间
void test1() {
    vector<int> nums{1, 2, 3, 4, 5};
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    nums.push_back(1);
    for (auto& ele : nums) {
        cout << ele << " ";
    }
    cout << endl;

    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    cout << endl;
    nums.pop_back();
    for (auto& ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    cout << endl;
    nums.shrink_to_fit();  // 释放多余的空间
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    cout << endl;
    nums.clear();
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;
}

void test2() {
    vector<int> nums{1, 2, 3, 4, 5};

    cout << &nums << endl;
    cout << &nums[0] << endl;
    // cout << &nums[1] << endl;

    vector<int>::iterator it = nums.begin();
    cout << &*nums.begin() << endl;

    // vector的元素一定在堆上
    // vector对象可以创建在栈上，也可以创建在堆上
    vector<int>* p = new vector<int>();
    p->push_back(10);
    delete p;
}

void test3() {
    // 如果一个vector要存放很多个元素

    // 这种有参构造不仅开辟了存放元素的空间
    // 而且对所有元素进行了初始化
    vector<int> nums(10);  // 这步开销有点大
    cout << "nums'size: " << nums.size() << endl;
    cout << "nums'capacity: " << nums.capacity() << endl;

    // 无参构造
    vector<int> nums2;
    nums2.reserve(10);  // 开辟空间，但是没有存放元素
    cout << "nums'size: " << nums2.size() << endl;
    cout << "nums'capacity: " << nums2.capacity() << endl;
}

int main(void) {
    test3();
    return 0;
}