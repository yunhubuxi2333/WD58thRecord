#include <iostream>
using std::cout;
using std::endl;

int val = 100;
void display() { cout << "display()" << endl; }
namespace wd {
int val = 300;
void display() { cout << "wd::display()" << endl; }
}  // namespace wd