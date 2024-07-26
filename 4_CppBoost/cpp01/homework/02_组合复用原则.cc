#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Vehicle {
   public:
    virtual void run() = 0;
    virtual ~Vehicle() {}
};

class BYD : public Vehicle {
   public:
    void run() override { cout << "yangwangU8 running...." << endl; }
};

class Tesla : public Vehicle {
   public:
    void run() override { cout << "Model X running...." << endl; }
};

class Zeekr : public Vehicle {
   public:
    void run() override { cout << "Zeekr001 running...." << endl; }
};

class Person {
   public:
    void getVehicle(Vehicle* vehicle) { _vehicle = vehicle; }
    void drive() { _vehicle->run(); }

   private:
    Vehicle* _vehicle;
};