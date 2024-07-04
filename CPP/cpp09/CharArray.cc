#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CharArray {
   public:
    CharArray(const char* pstr)
        : _capacity(strlen(pstr) + 1), _data(new char[_capacity]()) {
        strcpy(_data, pstr);
    }

    ~CharArray() {
        if (_data) {
            delete[] _data;
            _data = nullptr;
        }
    }

    // CharArray * const this
    char& operator[](size_t idx) {  // size_t是无符号整数
        if (idx < this->_capacity - 1) {
            return _data[idx];
        } else {
            cout << "out of range!" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }

    // const CharArray * const this
    // 函数返回类型中的const限定了返回值为一个const char &
    // 不能通过返回值进行写操作
    const char& operator[](size_t idx) const {  // size_t是无符号整数
        cout << "const版本的operator[]" << endl;
        if (idx < this->_capacity - 1) {
            // 这两个操作被函数声明中第二个const限定了
            _data[idx] = 'R';  // 只能人为避免这种修改，没有被限制
            return _data[idx];
        } else {
            cout << "out of range!" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }

   private:
    size_t _capacity;
    char* _data;
};

void test0() {
    char arr[] = "hello";
    cout << arr[0] << endl;

    const char arr2[] = "world";
    cout << arr2[0] << endl;
    // arr2[0] = 'Y';  // const不可被修改

    CharArray ca("hello");
    cout << ca[0] << endl;  // 下标访问函数重载，必须成员函数形式重载
    ca[0] = 'X';
    cout << ca[0] << endl;
    cout << ca[9] << endl;  // 越界的处理

    const CharArray ca2(
        "world");  // 一个手上有点钱无二无女的老人，只敢用公安局认证的软件
                   //    只敢调用const成员或者函数
    // ca2[0] = const 'W';
    cout << ca2[0] << endl;
}

int main() {
    test0();
    return 0;
}