#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

void display() {}
void test() {
    list<int> number = {11, 3, 5, 7, 9, 8, 6};
    display(number);
    list<int> other = {11, 44, 77, 99, 33, 22};
    auto it = number.begin();

    ++it;
    ++it;
    cout << "it = " << *it << endl;
    // number.splice(it, other);
    // display(number);
    // display(other);

    

}
int main(int argc, char argv[]) {
    test();
    return 0;
}