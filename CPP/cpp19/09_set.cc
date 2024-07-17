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

    ~Point() {}

    friend std::ostream& operator<<(std::ostream& os, const Point& rhs);
    friend bool operator<(const Point& lhs, const Point& rhs);

   private:
    int _ix;
    int _iy;
};

std::ostream& operator<<(std::ostream& os, const Point& rhs) {
    os << "(" << rhs._ix << "," << rhs._iy << ")";

    return os;
}

bool operator<(const Point& lhs, const Point& rhs) {
    if (lhs._ix != rhs._ix)
        return lhs._ix < rhs._ix;
    else
        return lhs._iy < rhs._iy;
}

void test0() {
    set<Point> number = {
        Point(1, 2), Point(-1, 2), Point(1, -2),
        Point(2, 2), Point(1, 2),  Point(3, 2),
    };
    display(number);
}

int main() {
    test0();
    return 0;
}
