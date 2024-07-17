#include <string.h>

#include <iostream>

using namespace std;

class Person {
   public:
    Person(const char* name, int age)
        : _name(new char[strlen(name) + 1]()), _age(age) {
        strcpy(_name, name);
        cout << "Person()" << endl;
    }

    void display() {
        cout << "name:" << _name << endl;
        cout << "age:" << _age << endl;
    }

    char* _name;
    int _age;
};

class Employee : public Person {
   public:
    Employee(const char* name, int age, char* department, double salary)
        : Person(name, age),
          _department(new char[strlen(department) + 1]()),
          _salary(salary) {
        strcpy(_department, department);
        cout << "Employee()" << endl;
    }

    Employee(const Employee& rhs)
        : Person(rhs._name, rhs._age),
          _department(new char[strlen(rhs._department) + 1]()),
          _salary(rhs._salary) {
        strcpy(_department, rhs._department);
        cout << "Employee的拷贝构造函数" << endl;
    }

    Employee& operator=(const Employee& rhs) {
        if (this != &rhs) {
            delete[] _department;
            _department = new char[strlen(rhs._department) + 1]();
            strcpy(_department, rhs._department);
            _salary = rhs._salary;
        }

        cout << "Employee的赋值运算符函数" << endl;
        return *this;
    }

    ~Employee() {
        if (_department) {
            delete[] _department;
            _department = nullptr;
            cout << "~Employee()" << endl;
        }
    }

    void display() {
        cout << "name:" << _name << endl;
        cout << "age:" << _age << endl;
        cout << "department:" << _department << endl;
        cout << "salary:" << _salary << endl;
    }

    char* _department;
    double _salary;
};

void test0() {
    Employee e1("peanut", 30, "研发部", 18000);
    Employee e2 = e1;
    e1.display();
    cout << endl;
    e2.display();
}

int main() {
    test0();
    return 0;
}