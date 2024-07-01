#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Stack {
   public:
    Stack(int size = 10) : _size(size), _top(-1), _data(new int[_size]()) {
        cout << "Stack(int)" << endl;
    }
    ~Stack() {
        cout << "~Stack()" << endl;
        if (_data) {
            delete[] _data;
            _data = nullptr;
        }
    }
    bool empty() {  // 判断栈是否为空

        return _top == -1;
    }
    bool full() {  // 判断栈是否已满

        return _top == _size - 1;
    }
    void push(int){  // 元素入栈
    
    }
    void pop();      // 元素出栈
    int top();       // 获取栈顶元素

   private:
    int _size;
    int _top;
    int* _data;
};

void test0() {
    Stack st(12);
    cout << "栈是不是空的?" << endl;
}

int main() {
    test0();
    return 0;
}