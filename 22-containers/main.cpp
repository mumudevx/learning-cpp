#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

int main() {
    // VECTOR (DYNAMIC ARRAYS)
    std::vector<int> numberVector = {1, 3, 5, 6, 7, 11};

    numberVector.push_back(55);

    std::cout << "Vector contains:";
    for (int i: numberVector) {
        std::cout << ' ' << i;
    }

    std::cout << std::endl;

    // LIST
    std::list<int> numberList = {1, 7, 33, 22};
    numberList.push_back(102);

    std::cout << "List contains:";
    for (int number: numberList) {
        std::cout << ' ' << number;
    }

    std::cout << std::endl;

    // MAP
    std::map<std::string, int> myMap;
    myMap["kak"] = 2;
    myMap["tat"] = 33;

    std::cout << "Map contains:" << std::endl;
    for (const auto &pair: myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // UNORDERED MAP
    std::unordered_map<std::string, int> unorderedMap;

    unorderedMap["mak"] = 22;
    unorderedMap["nak"] = 42;

    std::cout << "Unordered map contains:" << std::endl;
    for (const auto &pair: unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
