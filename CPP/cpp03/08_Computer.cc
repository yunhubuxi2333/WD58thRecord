#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

// 编程规范
// 类名遵循大驼峰原则
class Computer {
    // 类定义中如果没有显式写出访问修饰符
    // 默认是私有的访问权限
   public:
    // 成员函数的名称遵循小驼峰原则
    void setBrand(const char* brand) { strcpy(_brand, brand); }

    void setPrice(double price) { _price = price; }

    void print() {
        cout << "brand:" << _brand << endl;
        cout << "price" << _price << endl;
    }

   private:
    // 数据成员的名称前面加上下划线
    char _brand[20];
    double _price;
};

void test0() {
    cout << sizeof(Computer) << endl;
    int num;
    // pc称为Computer的对象
    Computer pc;
    pc.setBrand("ASUS");
    pc.setPrice(20000);
    // pc._brand;
    // pc._price;
    pc.print();
}
int main() {
    test0();
    return 0;
}
