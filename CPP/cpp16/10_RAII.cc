#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) { cout << "Point(int,int)" << endl; }
    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

   private:
    int _ix;
    int _iy;
};

template <class T>
class RAII {
   public:
    RAII(T* data) : _data(data) { cout << "RAII(T*)" << endl; }
    ~RAII() {
        cout << "~RAII()" << endl;
        if (_data) {
            delete _data;
            _data = nullptr;
        }
    }

    T* operator->() { return _data; }

    T& operator*() { return *_data; }

    // 获取底层的指针
    T* get() const { return _data; }

    // 重新管理一片资源
    void reset(T* data) {
        if (_data) {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII& rhs) = delete;
    RAII& operator=(const RAII& rhs) = delete;

   private:
    T* _data;
};

void test0() {
    int* p = new int(10);
    RAII<int> raii(p);

    cout << p << endl;
    cout << raii.get() << endl;
    cout << *raii << endl;
    cout << raii.operator*() << endl;
}

void test1() {
    RAII<Point> raii(new Point(1, 2));  // 构造函数
    raii->print();                      // 调用->函数
    (*raii).print();                    // 调用*.函数
    cout << raii.get() << endl;         // 调用get函数
    raii.reset(new Point(10, 9));       // 调用reset函数
    raii->print();
}

int main() {
    test1();
    return 0;
}