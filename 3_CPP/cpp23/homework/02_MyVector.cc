#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::uninitialized_copy;

template <typename T>
class Vector {
   public:
    using iterator = T*;

    iterator begin() { return _start; }

    iterator end() { return _finish; }

    Vector();
    ~Vector();

    void push_back(const T&);
    void pop_back();

    int size() const;
    int capacity() const;

   private:
    void reallocate();  // 重新分配内存,动态扩容要用的
   private:
    static std::allocator<T> _alloc;
    T* _start;           // 指向数组中的第一个元素
    T* _finish;          // 指向最后一个实际元素之后的那个元素
    T* _end_of_storage;  // 指向数组本身之后的位置
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
    : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

template <typename T>
Vector<T>::~Vector() {
    if (_start) {
        while (_start != _finish) {
            _alloc.destroy(--_finish);  // 销毁对象
        }
        _alloc.deallocate(_start, capacity());  // 释放空间
    }
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    // 是不是满的
    if (size() == capacity()) {
        // 需要扩容
        reallocate();
    }
    if (size() < capacity()) {
        // 在vector的尾部构建对象
        _alloc.construct(_finish++, value);
    }
}

template <typename T>
void Vector<T>::pop_back() {
    if (size() > 0) {
        // 销毁对象
        _alloc.destroy(--_finish);
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
void Vector<T>::reallocate() {
    // 1、申请两倍的空间
    int oldCapacity = capacity();
    int newCapacity = oldCapacity > 0 ? 2 * oldCapacity : 1;
    T* ptmp = _alloc.allocate(newCapacity);

    if (_start) {
        // 2、将老的空间上的对象拷贝到新空间来
        uninitialized_copy(_start, _finish, ptmp);
        // 3、然后将老的对象销毁
        while (_start != _finish) {
            _alloc.destroy(--_finish);
        }
        // 4、将老的空间回收
        _alloc.deallocate(_start, oldCapacity);
    }

    // 5、将三个指针指向新的空间
    _start = ptmp;
    _finish = ptmp + oldCapacity;
    _end_of_storage = ptmp + newCapacity;
}

void displayCapacity(const Vector<int>& con) {
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test0() {
    Vector<int> vec;
    displayCapacity(vec);

    cout << endl;
    vec.push_back(1);
    displayCapacity(vec);

    cout << endl;
    vec.push_back(2);
    displayCapacity(vec);

    cout << endl;
    vec.push_back(3);
    displayCapacity(vec);

    cout << endl;
    vec.push_back(4);
    displayCapacity(vec);

    cout << endl;
    vec.push_back(5);
    displayCapacity(vec);

    for (auto& elem : vec) {
        cout << elem << "  ";
    }
    cout << endl;
}

int main() {
    test0();
    return 0;
}