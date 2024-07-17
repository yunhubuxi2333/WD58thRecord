#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

// （2）实现只能创建堆对象，不能创建栈对象的Computer类.
class Computer {
   public:
    Computer(const char* brand, int price)
        : _brand(new char[strlen(brand) + 1]()), _price(price) {
        strcpy(_brand, brand);
        cout << "Computer()" << endl;
    }

    void* operator new(size_t sz) {
        cout << "operator new" << endl;
        void* ret = malloc(sz);
        return ret;
    }

    void operator delete(void* pointer) {
        cout << "operator delete" << endl;
        free(pointer);
    }

    void print() const {
        cout << "brand:" << _brand << endl << "price" << _price << endl;
    }

    void destroy() { delete this; }

   private:
    ~Computer() {
        cout << "~Computer()" << endl;
        if (_brand) {
            delete[] _brand;
            _brand = nullptr;
        }
    }

   private:
    char* _brand;
    int _price;
};

void test0() {
    Computer* pc = new Computer("Apple", 20000);
    pc->print();
    pc->destroy();
    pc = nullptr;
}

int main() {
    test0();
    return 0;
}