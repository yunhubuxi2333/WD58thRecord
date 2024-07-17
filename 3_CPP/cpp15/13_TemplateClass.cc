#include <iostream>
using std::cout;
using std::endl;

template <class T = int, int kCapacity = 10>
class Stack {
   public:
    Stack() : _top(-1), _data(new T[kCapacity]()) { cout << "Stack()" << endl; }
    ~Stack() {
        if (_data) {
            delete[] _data;
            _data = nullptr;
        }
        cout << "~Stack()" << endl;
    }
    bool empty() const { return _top == -1; }
    bool full() const { return _top == kCapacity - 1; }

    void push(const T& t) {
        if (!full()) {
            _data[++_top] = t;
        } else {
            cout << "栈已满！" << endl;
        }
    }

    void pop() {
        if (!empty()) {
            --_top;
        } else {
            cout << "栈已空！！！" << endl;
        }
    }

    T top();

   private:
    int _top;
    T* _data;
};

// 类模板成员函数在类外实现
// 需要加上完整的模板声明
template <class T, int kCapacity>
T Stack<T, kCapacity>::top() {
    if (!empty()) {
        return _data[_top];
    } else {
        throw "栈已空";
    }
}

void test0() {
    Stack<int, 20> s1;
    Stack<double> s2;
    Stack<> s3;
}

int main() {
    test0();
    return 0;
}