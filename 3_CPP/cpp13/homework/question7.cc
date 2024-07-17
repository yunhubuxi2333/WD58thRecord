#include <iostream>

using std::cout;
using std::endl;

class Base {
   public:
    Base(int i) { b = i; }
    
    Base() : b(0) {}
    virtual void Print() { cout << "Base 's Print() called." << endl; }

   protected:
    int b;
};

class Derive1 : public Base {
   public:
    virtual void Print() override {
        cout << "Derive1's Print() called." << endl;
    }
};

class Derive2 : public Base {
   public:
    virtual void Print() override {
        cout << "Derive2's Print() called. " << endl;
    }
};

// Base  * obj
void fun(Base* obj) { obj->Print(); }

int main(void) {
    Derive1 d1;
    Derive2 d2;
    fun(d1);
    fun(d2);
    return 0;
}