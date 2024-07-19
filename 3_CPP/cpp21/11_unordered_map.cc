#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::unordered_map;

template <typename Container>
void display(const Container& con) {
    for (auto& elem : con) {
        cout << elem.first << "  " << elem.second << endl;
    }
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
    os << "(" << rhs._ix << "," << rhs._iy << ")";

    return os;
}

void test0() {
    unordered_map<string, Point> number = {
        {"wangdao", Point(1, 2)},
        {"test", Point(1, 2)},
        pair<string, Point>("hubei", Point(-1, 2)),
        pair<string, Point>("wuhan", Point(-1, 2)),
        make_pair("beijing", Point(2, 4)),
        make_pair("beijing", Point(2, 4))
        };
    display(number);
}

int main() {
    test0();
    return 0;
}