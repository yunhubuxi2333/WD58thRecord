#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Building {
   public:
    Building() {}
    void sale() {}
    string getQuality() {}
};

class WankeBuilding : public Building {
   public:
    WankeBuilding() {}
    void sale() {}
    string getQuality() {}

   private:
    string _quality;
};

class HengdaBuilding : public Building {
   public:
    HengdaBuilding() {}
    void sale() {}
    string getQuality() {}

   private:
    string _quality;
};

class Mediator {
   public:
    Mediator() {}
    Building* findBuildings() {}
    ~Mediator() {}

   private:
    vector<Building*> _buildings;
};