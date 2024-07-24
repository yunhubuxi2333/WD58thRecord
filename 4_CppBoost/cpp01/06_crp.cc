#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class Vehicle {
   public:
    virtual void run() = 0;
    virtual ~Vehicle() {}
};

class Tesla : public Vehicle {
   public:
    void run() override { cout << "Model Y start..." << endl; }
};

class BYD : public Vehicle {
   public:
    void run() override { cout << "汉EV start..." << endl; }
};

class Geely : public Vehicle {
   public:
    void run() override { cout << "Geely LYNK03 start..." << endl; }
};

class Person {
   public:
    void getVehicle(Vehicle* vehicle) { _vehicle = vehicle; }

    void drive() { _vehicle->run(); }

   private:
    Vehicle* _vehicle;
};

void test() {
    Person person;
    unique_ptr<Vehicle> tesla(new Tesla());
    unique_ptr<Vehicle> han(new BYD());
    unique_ptr<Vehicle> geely(new Geely());

    person.getVehicle(tesla.get());
    person.drive();

    person.getVehicle(han.get());
    person.drive();

    person.getVehicle(geely.get());
    person.drive();
}

int main(int argc, char** argv) {
    test();
    return 0;
}