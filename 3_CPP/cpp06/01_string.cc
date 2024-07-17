#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0() {
    string str1;
    cout << "is str1 empty?" << str1.empty() << endl;

    string str2("hello");
    string str3 = "hello";
    cout << "is str2 empty?" << str2.empty() << endl;
    cout << "str3: " << str3 << endl;

    string str4("world", 3);  // 截取前3个
    cout << "str4: " << str4 << endl;

    string str5(str4);
    string str6 = str3;  // 赋值
    cout << "str6: " << str6 << endl;

    string str7(str6, 1, 3);  // 从1开始数3个数
    cout << "str7: " << str7 << endl;

    string str8(10, 'a');  // 10个'a'
    cout << "str8: " << str8 << endl;
}

// 迭代器方式创建string对象
void test1() {
    char arr[] = "hello";
    // 迭代器目前可以理解为广义的指针
    // 利用迭代器构造string对象时
    // 需要传入首迭代器(begin())和尾后迭代器
    // 使用两个迭代器之间（左闭右开）范围的元素作为string对象的内容
    string str1(arr, arr + 5);
    cout << str1 << endl;

    // 迭代器不等同于指针
    // begin函数返回string对象的首迭代器
    // char* p = str1.begin();

    // 把string视为是存放char型元素的容器
    // 容器类型名称::iterator就是这种容器的迭代器类型
    string::iterator it = str1.begin();
    // auto可以自动推导类型
    // string::iterator it2 = str1.end();
    auto it2 = str1.end();
    string str2(it, it2);
    // string str2(it, --it2);      // 创建的str为hell
    cout << str2 << endl;
}

void test2() {
    string str1("hello,");
    string str2("world");
    string str3 = 'A' + str1 + str2 + "!!!" + '!';
    cout << str3 << endl;
}

// string的常用操作
void test3() {
    string str1("hello");
    printf("%s\n", str1.c_str());

    // 得到的字符数不包含结尾空字符
    cout << str1.size() << endl;

    str1.push_back(',');
    cout << "str1: " << str1 << endl;

    str1.append(5, 'a');
    cout << "str1: " << str1 << endl;

    string str2(",world");

    cout << &str1 << endl;
    cout << &(str1.append(str2)) << endl;
    cout << "str1: " << str1 << endl;

    // &(str1 + str2);

    string str3("hello");
    string str4("el");
    size_t pos = str3.find(str4, 2);
    cout << pos << endl;  // 找不到的时候就会返回2的64次方-1
}

void test4() {
    string str1("wangdao");
    // 1.通过下标进行遍历
    for (size_t idx = 0; idx < str1.size(); idx++) {
        cout << str1[idx] << " ";
    }
    cout << endl;

    // 2.增强for循环
    //  通常与auto一起使用，auto用来自动推导容器中的元素类型
    //  ch代表容器中的元素
    //  :后面写上容器的名字（此处就是string对象的名字）
    //  引用符号代表在增强for循环中操作的是元素本身
    //  如果没有引用符号，操作的ch就是元素的副本
    for (auto ch : str1) {
        ++ch;
    }
    cout << endl;

    for (auto& ch : str1) {
        ++ch;
    }
    cout << endl;

    // 3.迭代器方式进行遍历
    //
    auto it = str1.begin();
    for (; it != str1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void) {
    // test0();
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}