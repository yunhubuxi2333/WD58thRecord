#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;

class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) {  // cout << "Point(int,int)" << endl;
    }

    void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }

    ~Point() { cout << "~Point()" << endl; }

   private:
    int _ix;
    int _iy;
};

void test0() {
    shared_ptr<int> sp(new int(30));
    cout << "sp = " << sp << endl;
    cout << sp.get() << endl;
    cout << sp.use_count() << endl;

    shared_ptr<int> sp2(sp);
    cout << sp2.get() << endl;
    cout << sp2.use_count() << endl;

    cout << endl;
    shared_ptr<int> sp3(new int(20));
    sp2 = sp3;

    // cout << endl;
    // sp2.reset(new int(10));
    // cout << sp2.get() << endl;
    // cout << sp2.use_count() << endl;

    shared_ptr<Point> spp(new Point(1, 2));
    (*spp).print();
    spp->print();
    cout << spp.use_count() << endl;
}

void test1() {
    shared_ptr<int> sp(new int(30));
    shared_ptr<int> sp2(sp);
    shared_ptr<int> sp3(new int(20));

    vector<shared_ptr<int>> vec;
    vec.push_back(sp);
    cout << sp.use_count() << endl;
    cout << *vec[0] << endl;

    cout << endl;
    vec.push_back(sp2);
    cout << sp2.use_count() << endl;

    vec.push_back(std::move(sp3));
    cout << "vec[2]" << endl;
    cout << sp3.use_count() << endl;

    vec.push_back(shared_ptr<int>(new int(50)));
    vec.push_back(std::move(sp2));
    
    cout << endl;
    cout << *vec[4] << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
}

int main() {
    test1();
    return 0;
}