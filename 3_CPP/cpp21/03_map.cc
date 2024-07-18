#include <math.h>

#include <iostream>
#include <map>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::string;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem.first << "  " << elem.second << endl;
    }
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

void test() {
    map<string, Point> number = {{"wangdao", Point(1, 2)},
                                 {"test", Point(1, 2)},
                                 pair<string, Point>("hubei", Point(-1, 2)),
                                 pair<string, Point>("wuhan", Point(-1, 2)),
                                 make_pair("beijing", Point(2, 4)),
                                 make_pair("beijing", Point(2, 4))};
    display(number);
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}