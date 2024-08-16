#include <iostream>

#include "nlohmann/json.hpp"
int main() {
    nlohmann::json json_object;  // 创建空的json对象
    json_object[0] = "value";    // json对象是一个array "value"
    json_object[1] = 123;
    json_object.push_back(1234);
    json_object[3]["key1"] = "value1";
    json_object[4][0] = "hello";
    nlohmann::json child_object;
    child_object.push_back("123");
    child_object.push_back("456");
    child_object.push_back("789");
    json_object.push_back(child_object);
    std::cout << json_object.dump() << "\n";  // dump方法 序列化
    return 0;
}