#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Student {
   public:
    void setId(int id) { _id = id; }
    void setHeight(double height) { _height = height; }
    void setName(const char* name) { strcpy(_name, name); }
    void setScore(double score) { _score = score; }
    void print() {
        cout << "学号是" << _id << endl;
        cout << "身高是" << _height << endl;
        cout << "姓名是" << _name << endl;
        cout << "成绩是" << _score << endl;
    }
    ~Student() {
        if (_name) {
            delete[] _name;
            _name = nullptr;
        }
        cout << "~Student()" << endl;
    }

   private:
    int _id;         // 学号
    double _height;  // 身高
    char* _name;     // 姓名
    double _score;   // 成绩
};
void test0() {
    Student stu;
    stu.setId(001);
    stu.setHeight(180.00);
    stu.setName("huwentao");
    stu.setScore(100.00);
    stu.print();
}
int main() {
    test0();
    return 0;
}
