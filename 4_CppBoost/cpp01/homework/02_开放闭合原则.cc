#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class Calculator {
   public:
    virtual int getResult(int a, int b) const = 0;
    virtual ~Calculator() {}
};

class PlusCalculator : public Calculator {
   public:
    int getResult(int a, int b) const override { return a + b; }
};

class MinusCalculator : public Calculator {
   public:
    int getResult(int a, int b) const override { return a - b; }
};

class MultiCalculator : public Calculator {
   public:
    int getResult(int a, int b) const override { return a * b; }
};

class DivCalculator : public Calculator {
   public:
    int getResult(int a, int b) const override {
        if (b == 0) {
            cerr << "Error!" << endl;
            return 0;
        }
        return a / b;
    }
};