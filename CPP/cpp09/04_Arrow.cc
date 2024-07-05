#include <iostream>
using std::cout;
using std::endl;

class Data {
   public:
    Data() { cout << "Data()" << endl; }
    ~Data() { cout << "~Data()" << endl; }

    int getData() const { return _data; }

   private:
    int _data = 10;
};

class MiddleLayer {
   public:
    MiddleLayer(Data* p) : _pdata(p) { cout << "MiddleLayer()" << endl; }
    ~MiddleLayer() {
        cout << "~MiddleLayer()" << endl;
        if (_pdata) {
            delete _pdata;
            _pdata = nullptr;
        }
    }

    Data* operator->() { return _pdata; }

    Data& operator*() { return *_pdata; }

    friend class ThirdLayer;

   private:
    Data* _pdata;
};

class ThirdLayer {
   public:
    ThirdLayer(MiddleLayer* ml) : _pml(ml) { cout << "ThirdLayer()" << endl; }

    ~ThirdLayer() {
        cout << "~ThirdLayer()" << endl;
        if (_pml) {
            delete _pml;
            _pml = nullptr;
        }
    }

    MiddleLayer& operator->() { return *_pml; }

    // 一步一步解引用

    // 2.一步到位解引用
    Data& operator*() { return *((*_pml)._pdata); }

   private:
    MiddleLayer* _pml;
};

void test2() {
    ThirdLayer tl(new MiddleLayer(new Data()));

    cout << ((tl.operator->()).operator->())->getData() << endl;
    cout << (tl.operator->())->getData() << endl;
    cout << tl->getData() << endl;

    // 2.一步到位解引用
    cout << (*tl).getData() << endl;
}

int main() {
    test2();

    return 0;
}