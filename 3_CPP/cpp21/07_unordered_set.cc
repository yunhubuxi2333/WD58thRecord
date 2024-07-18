#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

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
    size_t operator()(const Point& rhs) const {}
};  // end of struct hash
}  // namespace std

namespace std {
template <>
struct equal_to<Point> {
    bool operator()(const Point& lhs, const Point& rhs) const {
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};
}  // namespace std

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
