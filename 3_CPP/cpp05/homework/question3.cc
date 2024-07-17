#include <iostream>
using std::cout;
using std::endl;

class Point {
   public:
    static Point* getInstance() {
        if (_pInstance == nullptr) {
            _pInstance = new Point(1, 2);
        }

        return _pInstance;
    }

    void Init(int x, int y) {
        _ix = x;
        _iy = y;
    }

    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
            _pInstance = nullptr;
            cout << ">>delete heap" << endl;
        }
    }

    void print() const {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

   private:
    Point(const Point& rhs) = delete;
    Point& operator=(const Point& rhs) = delete;

    Point() = default;
    Point(int x, int y = 0) : _ix(x), _iy(y) {
        cout << "Point(int,int)" << endl;
    }

    ~Point() { cout << "~Point()" << endl; }

   private:
    int _ix;
    int _iy;
    static Point* _pInstance;
};

Point* Point::_pInstance = nullptr;

void test0() {
    Point::getInstance()->print();
    Point::getInstance()->Init(6, 7);
    Point::getInstance()->print();
    Point::destroy();
    Point::destroy();
    Point* a = Point::getInstance();
}

int main() {
    test0();
    return 0;
}