#include <iostream>
#include <list>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;

class Observer {
   public:
    virtual void update(int x) = 0;
    virtual ~Observer() {}
};

class ConcreteObserverA : public Observer {
   public:
    ConcreteObserverA(const string& name) : _name(name) {}
    virtual void update(int x) override {
        cout << "ConcreteObserverA name " << _name << "," << x << endl;
    }
    ~ConcreteObserverA() {}

   private:
    string _name;
};

class ConcreteObserverB : public Observer {
   public:
    ConcreteObserverB(const string& name) : _name(name) {}
    virtual void update(int x) override {
        cout << "ConcreteObserverB name " << _name << "," << x << endl;
    }
    ~ConcreteObserverB() {}

   private:
    string _name;
};

class Subject {
   public:
    // 添加
    virtual void attach(Observer* pobserver) = 0;
    // 删除
    virtual void detach(Observer* pobserver) = 0;
    // 发通知
    virtual void notify() = 0;

    virtual ~Subject() {}
};

class ConcreteSubject : public Subject {
   public:
    ConcreteSubject() {}

    // 添加
    virtual void attach(Observer* pobserver) override {
        if (pobserver) {
            _obtList.push_back(pobserver);
        }
    }

    // 删除
    virtual void detach(Observer* pobserver) override {
        if (pobserver) {
            _obtList.remove(pobserver);
        }
    }

    // 发通知
    virtual void notify() override {
        for (auto& ob : _obtList) {
            ob->update(_status);
        }
    }

    void setStatus(int status) { _status = status; }

    int getStatus() { return _status; }

    ~ConcreteSubject() {}

   private:
    int _status;  // 状态
    list<Observer*> _obtList;
};

void test0() {
    unique_ptr<ConcreteSubject> psub(new ConcreteSubject());
    unique_ptr<Observer> poa(new ConcreteObserverA("lili"));
    unique_ptr<Observer> pob(new ConcreteObserverB("lucy"));

    // 将观察者添加到主题上
    psub->attach(poa.get());
    psub->attach(pob.get());
    // 如果主题的状态发生变更
    psub->setStatus(2);
    // 发通知
    psub->notify();

    cout << endl;
    // 假如某个观察者不想关注主题的变更了
    psub->detach(pob.get());
    // 如果主题的状态发生变更
    psub->setStatus(3);
    // 发通知
    psub->notify();
}

int main() {
    test0();
    return 0;
}