#include <iostream>

#include "nlohmann/json.hpp"

int main() {
    nlohmann::json json_object;
    json_object["key"] = "value";
    std::cout << json_object.dump() << "\n";

    return 0;
}
