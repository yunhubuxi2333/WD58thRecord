#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class User {
   public:
    User(const string& name) {}
    void consume(float delta) {}

   protected:
    string _name;
    float _score;
};

class VipUser : public User {
   public:
    VipUser(const string& name) {}
    void consume2(float delta) {}
    void updateDiscount() {}

   private:
    float _discount;
};