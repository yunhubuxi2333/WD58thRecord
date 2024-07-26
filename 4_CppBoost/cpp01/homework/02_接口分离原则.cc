#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Bird {
   public:
    void eat();
    void walk();
    void chirp();
};

class FlyingBird : public Bird {
   public:
    void fly();
};

class Crow : public FlyingBird {};

class Ostrich : public Bird {};