#include <iostream>

#include "nlohmann/json.hpp"
int main() {
    nlohmann::json json_object;    // 创建空的json对象
    json_object["key"] = "value";  // json对象是一个object "key":"value"
    std::cout << json_object.dump() << "\n";  // dump方法 序列化
    return 0;
}