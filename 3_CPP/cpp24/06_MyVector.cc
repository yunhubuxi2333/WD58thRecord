#include <iostream>
#include <memory>

using std::cout;
using std::endl;

template <typename T>
class Vector {
   public:
    /* typedef T* iterator; */
    using iterator = T*;

    iterator begin() { return _start; }
    iterator end() { return _finish; }

    Vector();

    ~Vector();

    void push_back(const T& value);

    void pop_back();

    int size() const;

    int capacity() const;

   private:
    void reallocate();  // 重新分配内存,动态扩容要用的
   private:
    static std::allocator<T> _alloc;  // 空间的申请与对象的构建分开

    T* _start;           // 指向数组中的第一个元素
    T* _finish;          // 指向最后一个实际元素之后的那个元素
    T* _end_of_storage;  // 指向数组本身之后的位置
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;  // 静态数据成员的初始化

template <typename T>
Vector<T>::Vector()
    : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

template <typename T>
Vector<T>::~Vector() {
    if (_start) {
        while (_start != _finish) {
            // 销毁对象
            _alloc.destroy(--_finish);
        }

        // 回收空间
        _alloc.deallocate(_start, capacity());
    }
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size() == capacity()) {
        // 就需要扩容
        reallocate();
    }

    if (size() < capacity()) {
        // 将对象value放在_finish的位置
        _alloc.construct(_finish++, value);
    }
}

template <typename T>
void Vector<T>::pop_back() {
    if (size() > 0) {
        // 销毁对象
        _alloc.detroy(--_finish);
    }
}

template <typename T>
int Vector<T>::size() const {
    return _finish - _start;
}

template <typename T>
int Vector<T>::capacity() const {
    return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::reallocate() {  // 重新分配内存，动态扩容要用的
    // 1、申请两倍的空间
    int oldCapacity = size();
    int newCapacity = oldCapacity > 0 ? 2 * oldCapacity : 1;

    T* ptmp = _alloc.allocate(newCapacity);

    if (_start) {
        // 2、将老的空间上的元素拷贝到新的空间去
        std::uninitialized_copy(_start, _finish, ptmp);
        // 3、将老的空间上的对象销毁掉，并且将老的空间回收
        while (_start != _finish) {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, oldCapacity);
    }

    // 4、三个指针需要与新的空间产生关系（三个指针需要置位）
    _start = ptmp;
    _finish = ptmp + oldCapacity;
    _end_of_storage = ptmp + newCapacity;
}

void printCapacity(const Vector<int>& con) {
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test() {
    Vector<int> vec;
    printCapacity(vec);

    cout << endl;
    vec.push_back(1);
    printCapacity(vec);

    cout << endl;
    vec.push_back(2);
    printCapacity(vec);

    cout << endl;
    vec.push_back(3);
    printCapacity(vec);

    cout << endl;
    vec.push_back(4);
    printCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printCapacity(vec);

    cout << endl;
    vec.push_back(6);
    printCapacity(vec);

    cout << endl;
    vec.push_back(7);
    printCapacity(vec);

    cout << endl;
    vec.push_back(7);
    printCapacity(vec);

    cout << endl;
    vec.push_back(7);
    printCapacity(vec);

    cout << endl;
    for (auto& elem : vec) {
        cout << elem << "  ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}