#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_set;
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

    int getX() const { return _ix; }

    int getY() const { return _iy; }

    ~Point() {}

    friend std::ostream& operator<<(std::ostream& os, const Point& rhs);

   private:
    int _ix;
    int _iy;
};

std::ostream& operator<<(std::ostream& os, const Point& rhs) {
    os << "(" << rhs._ix << ", " << rhs._iy << ")";

    return os;
}

namespace std {
template <>
struct hash<Point> {
    size_t operator()(const Point& rhs) const {
        cout << "struct hash<Point>" << endl;
        return (rhs.getX() << 2) ^ (rhs.getY() << 3);
    }
};  // end of struct hash
}  // namespace std

struct HashPoint {
    size_t operator()(const Point& rhs) const {
        cout << "struct HashPoint" << endl;
        return (rhs.getX() << 2) ^ (rhs.getY() << 3);
    }
};

namespace std {
template <>
struct equal_to<Point> {
    bool operator()(const Point& lhs, const Point& rhs) const {
        cout << "struct equal_to<Point> " << endl;
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};
}  // namespace std

bool operator==(const Point& lhs, const Point& rhs) {
    cout << "bool operator==" << endl;
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

struct EqualToPoint {
    bool operator()(const Point& lhs, const Point& rhs) const {
        cout << "struct  EqualToPoint" << endl;
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};

void test0() {
    unordered_set<Point> number = {
        Point(1, 2), Point(-1, 2), Point(1, -2),
        Point(2, 2), Point(1, 2),  Point(3, 2),
    };
    display(number);
}

int main(int argc, char* argv[]) {
    test0();
    return 0;
}
