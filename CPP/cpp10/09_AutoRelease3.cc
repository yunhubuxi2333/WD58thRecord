#include <iostream>
using std::cout;
using std::endl;

class Singleton {
   public:
    static Singleton* getInstance() {
        if (_pInstance == nullptr) {
            atexit(destroy);
            _pInstance = new Singleton(1, 2);
        }
        return _pInstance;
    }

    void init(int x, int y) {
        _ix = x;
        _iy = y;
    }

    void print() const {
        cout << "(" << this->_ix << " " << this->_iy << ")" << endl;
    }

   private:
    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
            _pInstance = nullptr;
            cout << " >> delete heap" << endl;
        }
    }

    Singleton(const Singleton& rhs) = delete;
    Singleton&operator=(const Singleton & rhs) = delete;
    Singleton(int x,int y = 0)
    :_ix(x),
    _iy(y){
        cout<<"Singleton"
    }
   private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
};