#include <iostream>
using std::cout;
using std::endl;

class Sample {
    int _i;

   public:
    Sample();
    Sample(int val);
    void Display();
    ~Sample();
};
Sample::Sample() {
    cout << "Constructor1" << endl;
    _i = 0;
}
Sample::Sample(int i) { _i = i; }
void Sample::Display() { cout << "i = " << _i << endl; }

Sample::~Sample() {
    cout << "Destructor" << endl;
    this->Display();
}

Sample c(3);
int main() {
    Sample* pa = new Sample();
    Sample b(2);
    static Sample d(4);
    delete pa;

    return 0;
}
