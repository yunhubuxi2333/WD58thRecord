#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
   public:
    Computer(const char* brand, double price)
        : _brand(new char[strlen(brand) + 1]()), _price(price) {
        strcpy(_brand, brand);
    }

    ~Computer() {
        cout << "~Computer()" << endl;
        /* cout << _brand << endl; */
        if (_brand) {
            delete[] _brand;
            _brand = nullptr;  // 安全回收
        }
    }

    void print() {
        // 输出流运算符对char*指针的默认重载效果
        // 会直接访问指针所指向的地址上的内容
        // 如果<< 接的是一个char*空指针，会导致中断
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

   private:
    char* _brand;
    double _price;
};

Computer pc3("XiaoMi", 5000);

void test0() {
    static Computer pc4("Lenovo", 7000);

    /* cout << sizeof(Computer) << endl; */
    Computer pc("Apple", 20000);
    /* pc.print(); */
    // 手动调用析构函数只会回收数据成员申请的堆空间
    // 不会销毁对象
    //
    // 对象销毁时，一定会自动调用析构函数
    // 一般情况下不建议手动调用析构函数
    // 让析构函数在对象销毁时自动被调用
    /* pc.~Computer(); */
    /* pc.~Computer(); */
    /* pc.~Computer(); */
    /* pc.~Computer(); */
    /* pc.~Computer(); */
    /* pc.print(); */
    /* cout << pc._price << endl; */

    Computer pc2("Huawei", 21000);
    /* pc2.print(); */

    Computer* p = new Computer("Acer", 8000);
    p->print();
    (*p).print();
    delete p;
    p = nullptr;

    int* pint = new int(10);
    delete pint;
    pint = nullptr;

    /* cout << endl; */
    /* cout << "&pc2:" << &pc2 << endl; */
    /* cout << "&pc:" << &pc << endl; */
    /* cout << "&pc4:" << &pc4 << endl; */
    /* cout << "&pc3:" << &pc3 << endl; */

    /* cout << sizeof(pc) << endl; */
    /* cout << sizeof(pc2) << endl; */
}

void test1() {
    char* p = nullptr;
    cout << p << endl;
    cout << "over" << endl;
}

int main(void) {
    test0();
    return 0;
}