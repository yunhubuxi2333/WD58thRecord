#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
   public:
    Computer(const char* brand, double price)
        : _brand(new char[strlen(brand) + 1]()), _price(price) {
        strcpy(_brand, brand);
    }

    ~Computer() {
        cout << "~Computer()" << endl;
        if (_brand) {
            delete[] _brand;
            _brand = nullptr;
        }
    }

    void print() {
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

   private:
    char* _brand;
    double _price;
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
    RAII<Computer> raii(new Computer("Apple", 20000));
    raii->print();
    cout << raii.get() << endl;
    raii.reset(new Computer("HUAWEI", 18000));
    raii->print();
}

int main() {
    test0();
    return 0;
}