#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Student {
   public:
    Student(int id, const char* name)
        : _id(id), _name(new char[strlen(name) + 1]()) {
        strcpy(_name, name);
        cout << "Student()" << endl;
    }

    ~Student() {
        cout << "~Student()" << endl;
        if (_name) {
            delete[] _name;
            _name = nullptr;
        }
    }

    void print() const {
        cout << "id:" << _id << endl << "name:" << _name << endl;
    }

    void destroy() { delete this; }

   private:
    void* operator new(size_t sz) {
        cout << "operator new" << endl;
        void* ret = malloc(sz);
        return ret;
    }

    void operator delete(void* pointer) {
        cout << "operator delete" << endl;
        free(pointer);
    }

   private:
    int _id;
    char* _name;
};

void test0() {
    Student stu(101, "Jackie");
    // Student* p = new Student(100, "Jack");
    stu.print();
}

int main(void) {
    test0();
    return 0;
}