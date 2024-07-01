#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
   public:
    void setBrand(const char* brand);

    void setPrice(double price);

    void print();

   private:
    char _brand[20];
    double _price;
};

void Computer::setBrand(const char* brand) { strcpy(_brand, brand); }

void Computer::setPrice(double price) { _price = price; }

void Computer::print() {
    cout << "brand:" << _brand << endl;
    cout << "price" << _price << endl;
}

void test0() {
    Computer pc;
    pc.setBrand("Apple");
    pc.setPrice(200000);
    pc.print();
}
int main() {
    test0();
    return 0;
}
