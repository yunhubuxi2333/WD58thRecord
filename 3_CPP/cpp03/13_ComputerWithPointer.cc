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

    void print() {
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

   private:
    char* _brand;
    double _price;
};

void test0() {
    Computer pc("apple", 20000);
    pc.print();
}
int main() {
    test0();
    return 0;
}