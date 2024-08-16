#include <iostream>

#include "nlohmann/json.hpp"
int main() {
    char str[] = "[1,2,3,{\"key\":456}]";
    // nlohmann::json::parse 可以解析字符串
    nlohmann::json json_object = nlohmann::json::parse(str);
    std::cout << "json_object[0] " << json_object[0] << "\n";
    std::cout << "json_object[3][\"key\"] " << json_object[3]["key"] << "\n";
    return 0;
}