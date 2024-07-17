#include <iostream>
using std::cout;
using std::endl;

class Singleton {
    class AutoRelease {
       public:
        AutoRelease() { cout << "AutoRelease()" << endl; }

        ~AutoRelease() {
            cout << "~AutoRelease()" << endl;
            if (_pInstance) {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

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

    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
            _pInstance = nullptr;
            cout << ">> delete heap" << endl;
        }
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

   private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
    static AutoRelease _ar;
};

// 饱汉式
Singleton* Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_ar;

void test0() {
    Singleton::getInstance()->init(7, 8);
    Singleton::getInstance()->print();
}

int main(void) {
    test0();
    return 0;
}