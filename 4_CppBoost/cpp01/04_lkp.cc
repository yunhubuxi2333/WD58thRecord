#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Building {
   public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
    virtual ~Building() {}
};

class WankeBuilding : public Building {
   public:
    WankeBuilding() : _quality("高品质") {}

    void sale() override {
        cout << "万科楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override { return _quality; }

   private:
    string _quality;
};

class HengdaBuilding : public Building {
   public:
    HengdaBuilding() : _quality("低品质") {}

    void sale() override {
        cout << "恒大楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override { return _quality; }

   private:
    string _quality;
};

void test() {
    Building* pbuidingA = new WankeBuilding();
    Building* pbuidingB = new HengdaBuilding();

    string demand = "低品质";

    if (pbuidingA->getQuality() == demand) {
        pbuidingA->sale();
    }

    if (pbuidingB->getQuality() == demand) {
        pbuidingB->sale();
    }
}

int main(int argc, char** argv) {
    test();
    return 0;
}