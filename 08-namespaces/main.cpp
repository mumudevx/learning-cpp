#include <iostream>

namespace animals {
    std::string dog = "Cash";
    std::string cat = "Zilli";
}

namespace food {
    int cheeseAmount = 2;

    namespace vegetables {
        int cabbageAmount = 3;
        int carrotAmount = 5;
    }
}

int main() {
    // One level namespace
    std::cout << "Dog's name: " << animals::dog << std::endl;
    std::cout << "Cat's name: " << animals::cat << std::endl;

    // Inner namespace access
    std::cout << "Cheese amount: " << food::cheeseAmount << std::endl;
    std::cout << "Cabbage amount: " << food::vegetables::cabbageAmount << std::endl;
    std::cout << "Carrot amount: " << food::vegetables::carrotAmount << std::endl;

    return 0;
}
