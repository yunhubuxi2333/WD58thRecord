#include <math.h>

#include <iostream>
#include <set>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::vector;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem << "  ";
    }
    cout << endl;
}

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

#if 0
namespace std {
template <class T>
struct less {
    bool operator()(const T& lhs, const T& rhs) const { return lhs < rhs; }
};
}
#endif

// 模板的特化版本
namespace std {
// 模板的全特化（将模板参数列表中的参数全部以特殊版本的形式展现出来）
template <>
struct less<Point> {
    bool operator()(const Point& lhs, const Point& rhs) const {
        cout << "bool operator<" << endl;
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

void test0() {
    set<Point> number = {
        /* set<Point, ComparePoint>  number = { */
        Point(1, 2), Point(-1, 2), Point(1, -2),
        Point(2, 2), Point(1, 2),  Point(3, 2),
    };
    display(number);
}

int main(int argc, char* argv[]) {
    test0();
    return 0;
}