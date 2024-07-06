#include <iostream>
using std::cout;
using std::endl;

class Singleton {
   public:
    static Singleton* getInstance() {
        if (_pInstance == nullptr) {
            _pInstance = new Singleton(1, 2);
        }
        return _pInstance;
    }

    void init(int x, int y) {
        _ix = x;
        _iy = y;
    }

    void print() const {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

   private:
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;
    Singleton(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Singleton(int,int)" << endl;
    }
    ~Singleton() { cout << "~Singleton()" << endl; }

    friend class AutoRelease;

   private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
};
// 饱汉式
Singleton* Singleton::_pInstance = nullptr;

class AutoRelease {
   public:
    AutoRelease(Singleton* p) : _p(p) {
        cout << "AutoRelease(Singleton*)" << endl;
    }

    ~AutoRelease() {
        cout << "~AutoRelease()" << endl;
        if (_p) {
            delete _p;
            _p = nullptr;
        }
    }

   private:
    Singleton* _p;
};

void test0() {
    AutoRelease ar(Singleton::getInstance());
    Singleton::getInstance()->init(7, 8);
    Singleton::getInstance()->print();
}

int main(void) {
    test0();
    return 0;
}