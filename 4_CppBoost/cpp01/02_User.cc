#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class User {
   public:
    User(const string& name) : _name(name), _score(0) {}

    void consume(float delta) {
        cout << "void User::consume(float)" << endl;
        _score += delta;

        cout << ">>" << _name << "消费" << delta << endl;
    }

   protected:
    string _name;
    float _score;
};

class VipUser : public User {
   public:
    VipUser(const string& name) : User(name), _discount(1) {}

    void consume2(float delta)
    /* void consume(float delta) */
    {
        cout << "void VipUser::consume(float)" << endl;
        float tmp = delta * _discount;
        _score += tmp;

        if (_score > 1000 && _score < 9000) {
            _discount = 0.9;
        }

        cout << ">>" << _name << "消费" << tmp << endl;
    }

   private:
    float _discount;
};

void test() {
    User user("lili");
    user.consume(2000);
    user.consume(2000);
    user.consume(2000);
    user.consume(2000);

    cout << endl;
    VipUser vip("lucy");
    vip.consume(2000);  // 隐藏
    vip.consume(2000);  // 隐藏
    vip.consume2(2000);
    vip.consume2(2000);  // 增加了自己的个性
}

int main(int argc, char** argv) {
    test();
    return 0;
}