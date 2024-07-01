#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
   public:
    Computer(const char* brand, double price)  // 有参构造
        : _brand(new char[strlen(brand) + 1]()), _price(price) {
        cout << "Computer(const char *,double)" << endl;
        strcpy(_brand, brand);
    }

    ~Computer() {
        cout << "~Computer()" << endl;
        if (_brand) {
            delete[] _brand;
            _brand = nullptr;  // 安全回收
        }
    }

    // 默认的拷贝构造不够用
    /* Computer(const Computer & rhs) */
    /* : _brand(rhs._brand)//浅拷贝 */
    /* , _price(rhs._price) */
    /* { */
    /*     cout << "Computer(const Computer &)" << endl; */
    /* } */

    Computer(const Computer& rhs)  // 深拷贝
        : _brand(new char[strlen(rhs._brand) + 1]()), _price(rhs._price) {
        cout << "Computer(const Computer &)" << endl;
        strcpy(_brand, rhs._brand);
    }

    void print() {
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

   private:
    char* _brand;
    double _price;
};

void test0() {
    Computer pc("Apple", 20000);
    Computer pc2 = pc;
    pc2.print();
}

int main(void) {
    test0();
    return 0;
}