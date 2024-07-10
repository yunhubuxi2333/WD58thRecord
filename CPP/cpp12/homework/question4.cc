#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class String {
   public:
    String(const char* pstr) {
        _size = strlen(pstr);
        if (_size <= 15) {
            _capacity = 15;
            bzero(_buffer._local, sizeof(_buffer._local));
            strcpy(_buffer._local, pstr);
        } else {
            _capacity = _size;
            _buffer._pointer = new char[strlen(pstr) + 1]();
            strcpy(_buffer._pointer, pstr);
        }
    }

    String(const String& rhs) : _size(rhs._size), _capacity(rhs._capacity) {
        if (_size <= 15) {
            bzero(_buffer._local, sizeof(_buffer._local));
            strcpy(_buffer._local, rhs._buffer._local);
        } else {
            _buffer._pointer = new char[rhs._capacity + 1]();
            strcpy(_buffer._pointer, rhs._buffer._pointer);
        }
    }

    ~String() {
        if (_size > 15) {
            delete[] _buffer._pointer;
            _buffer._pointer = nullptr;
        }
    }

    char& operator[](size_t idx) {
        if (idx > _size) {
            cout << "out of range!!!" << endl;
            static char nullchar = '\0';
            return nullchar;
        }

        if (idx > 15) {
            return _buffer._pointer[idx];
        } else {
            return _buffer._local[idx];
        }
    }

    friend ostream& operator<<(ostream& os, const String& rhs);

   private:
    union Buffer {
        char* _pointer = nullptr;
        char _local[16];
    };

    size_t _size;
    size_t _capacity;
    Buffer _buffer;
};

ostream& operator<<(ostream& os, const String& rhs) {
    if (rhs._size <= 15) {
        os << rhs._buffer._local;
    } else {
        os << rhs._buffer._pointer;
    }

    return os;
}

void test0() {
    String str1("hello");
    String str2("hello,world!!!!!");

    // cout << str1 << endl;
    // cout << &str1 << endl;
    // printf("%p\n", &str1[0]);
    // cout << str1[0] << endl;
    // str1[0] = 'H';
    // cout << str1 << endl;

    // cout << endl;

    cout << str2 << endl;
    cout << &str2 << endl;
    printf("%p\n", &str2[0]);

    cout << str2 << endl;
    cout << endl;

    String str3 = str1;
    cout << str3 << endl;
    String str4 = str2;
    cout << str4 << endl;
}

int main() {
    test0();
    return 0;
}