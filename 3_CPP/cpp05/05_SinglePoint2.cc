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

    void init(int x, int y) {
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
    // 从本类中删除拷贝构造和赋值运算符函数
    // 严格禁止进行复制或赋值
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

#if 1
void test0() {
    cout << sizeof(Point) << endl;
    Point* p1 = Point::getInstance();
    Point* p2 = Point::getInstance();
    cout << p1 << endl;
    cout << p2 << endl;
    p1->print();
    p2->print();
    p1->destroy();
    p2->destroy();
}
#endif

void test1() {
    // 单例模式的规范写法
    // 直接使用getInstance函数的返回值（指针）
    // 来控制单例对象
    Point::getInstance()->print();
    Point::getInstance()->init(7, 8);
    Point::getInstance()->print();
    Point::getInstance()->init(29, 81);
    Point::getInstance()->print();
    Point::destroy();
    Point::destroy();
    Point::destroy();
    Point::getInstance()->print();
    Point::destroy();

    // 如果destroy是普通的成员函数
    // 那么如下多次调用destroy
    // 后几次会创建新的Point对象，并马上销毁，不合理
}

int main() {
    test1();
    return 0;
}