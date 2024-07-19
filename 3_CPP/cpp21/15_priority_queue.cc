#include <math.h>

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

class Point {
   public:
    Point(int ix = 0, int iy = 0) : _ix(ix), _iy(iy) {}

    float getDistance() const { return hypot(_ix, _iy); }

    int getX() const { return _ix; }

    int getY() const { return _iy; }

    ~Point() {}

    friend std::ostream& operator<<(std::ostream& os, const Point& rhs);
    friend bool operator<(const Point& lhs, const Point& rhs);
    friend struct ComparePoint;

   private:
    int _ix;
    int _iy;
};

std::ostream& operator<<(std::ostream& os, const Point& rhs) {
    os << "(" << rhs._ix << ", " << rhs._iy << ")";

    return os;
}

// std::less针对Point的特化
// 函数对象
// operator<重载

// 运算符重载的版本
bool operator<(const Point& lhs, const Point& rhs) {
    cout << "bool operator<" << endl;
    if (lhs.getDistance() < rhs.getDistance()) {
        return true;
    } else if (lhs.getDistance() == rhs.getDistance()) {
        if (lhs._ix < rhs._ix) {
            return true;
        } else if (lhs._ix == rhs._ix) {
            if (lhs._iy < rhs._iy) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// 函数对象的版本
struct ComparePoint {
    bool operator()(const Point& lhs, const Point& rhs) const {
        cout << "bool ComparePoint" << endl;
        if (lhs.getDistance() < rhs.getDistance()) {
            return true;
        } else if (lhs.getDistance() == rhs.getDistance()) {
            if (lhs._ix < rhs._ix) {
                return true;
            } else if (lhs._ix == rhs._ix) {
                if (lhs._iy < rhs._iy) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

// 模板的特化版本
namespace std {
// 模板的全特化（将模板参数列表中的参数全部以特殊版本的形式展现出来）
template <>
struct less<Point> {
    bool operator()(const Point& lhs, const Point& rhs) const {
        cout << "bool ComparePoint" << endl;
        if (lhs.getDistance() < rhs.getDistance()) {
            return true;
        } else if (lhs.getDistance() == rhs.getDistance()) {
            if (lhs.getX() < rhs.getX()) {
                return true;
            } else if (lhs.getX() == rhs.getX()) {
                if (lhs.getY() < rhs.getY()) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};
}  // namespace std

void test() {
    priority_queue<Point> pque;
    vector<Point> vec = {
        Point(1, -2), Point(1, 2), Point(-1, 2),
        Point(1, 2),  Point(3, 2), Point(-1, -2),
    };
    for (size_t idx = 0; idx != vec.size(); ++idx) {
        pque.push(vec[idx]);
        cout << "优先级最高的元素" << pque.top() << endl;
    }

    cout << endl;
    while (!pque.empty()) {
        cout << pque.top() << "  ";
        pque.pop();
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}