#include <iostream>
#include <vector>
#include <string>
#include <variant>

using std::string, std::vector, std::variant;

class tockenizer {
    variant<char, int, string, float> result;
};

int main() {
    variant<int, std::string> a;
    std::cout << 1.0 << std::endl;
}


