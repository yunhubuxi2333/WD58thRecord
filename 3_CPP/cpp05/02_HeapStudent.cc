#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Student {
   public:
    Student(int id, const char* name)
        : _id(id)
        , _name(new char[strlen(name) + 1]())               // 在堆空间申请空间
        {
        strcpy(_name, name);
        cout << "Student()" << endl;
    }

    void* operator new(size_t sz) {
        cout << "operator new" << endl;
        void* ret = malloc(sz);
        return ret;
    }

    void operator delete(void* pointer) {
        cout << "operator delete" << endl;
        free(pointer);
    }

    void print() const {
        cout << "id:" << _id << endl << "name:" << _name << endl;
    }

    void destroy() { delete this; }

   private:
    ~Student() {
        cout << "~Student()" << endl;
        if (_name) {
            delete[] _name;
            _name = nullptr;
        }
    }

    int _id;
    char* _name;
};

void test0() {
    Student* stu = new Student(100, "Jackie");
    stu->print();
    stu->destroy();
    stu = nullptr;

    /* free(stu);//没有调用析构函数，仍然有内存泄露 */

    /* delete stu; */
    /* stu = nullptr; */
}

int main(void) {
    test0();
    return 0;
}