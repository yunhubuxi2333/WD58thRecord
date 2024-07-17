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

    bool empty() const {  // 判断栈是否为空

        return _top == -1;
    }

    bool full() const {  // 判断栈是否已满

        return _top == _size - 1;
    }

    void push(const int& value) {  // 元素入栈
        if (!full()) {
            _data[++_top] = value;
        } else {
            cout << "The stack is full!" << endl;
            return;
        }
    }

    void pop() {  // 元素出栈
        if (!empty()) {
            --_top;
        } else {
            cout << "The stack is empty!" << endl;
            return;
        }
    }

    int top() const {  // 获取栈顶元素
        if (!empty()) {
            return _data[_top];
        } else {
            cout << "The stack is empty!" << endl;
        }
    }

   private:
    int _size;
    int _top;
    int* _data;
};

void test0() {
    Stack st(12);
    cout << "栈是不是空的?" << st.empty() << endl;
    st.push(13);
    cout << "栈是不是满的" << st.full() << endl;

    for (int idx = 2; idx != 15; idx++) {
        st.push(idx);
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "栈是不是空的?" << st.empty() << endl;
}

int main() {
    test0();
    return 0;
}