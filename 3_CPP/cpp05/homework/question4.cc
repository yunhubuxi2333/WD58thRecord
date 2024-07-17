#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
   public:
    static Computer* getInstance() {
        if (_pInstance == nullptr) {
            _pInstance = new Computer("Apple", 20000);
        }
        return _pInstance;
    }

    void init(const char* brand, int price) {
        strcpy(_brand, brand);
        _price = price;
    }

    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
            _pInstance = nullptr;
            cout << ">>delete heap" << endl;
        }
    }
    void print() const {
        cout << "brand:" << this->_brand << endl;
        cout << "price:" << this->_price << endl;
    }

   private:
    Computer(const Computer& rhs) = delete;
    Computer& operator=(const Computer& rhs) = delete;

    Computer() = default;

    Computer(const char* brand, int price)
        : _brand(new char[strlen(brand) + 1]()), _price(price) {
        strcpy(_brand, brand);
        cout << "Computer(char*,int)" << endl;
    }

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
    static Computer* _pInstance;
};
Computer* Computer::_pInstance = nullptr;

void test0() {
    Computer::getInstance()->print();
    Computer::getInstance()->init("huawei", 21000);
    Computer::getInstance()->print();
    Computer::getInstance()->destroy();
}

int main() {
    test0();
    return 0;
}