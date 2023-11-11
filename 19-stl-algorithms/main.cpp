#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    // SORTING ALGORITHM
    std::vector<int> numbers = {30, 5, 2, 1};
    std::sort(numbers.begin(), numbers.end());

    for (int number: numbers) {
        std::cout << number << ' ';
    }

    std::cout << std::endl;

    // SEARCHING ALGORITHM
    // std::find, std::binary_search, std::find_if
    std::vector<int> numberList = {5, 6, 7, 8, 9, 10};
    auto iterator = std::find(numberList.begin(), numberList.end(), 9);

    if (iterator != numberList.end()) {
        std::cout << "Found 9 at position: " << (iterator - numberList.begin());
    } else {
        std::cout << "9 not found";
    }

    std::cout << std::endl;

    // MODIFYING SEQUENCES
    // std::remove, std::replace, std::unique
    std::vector<int> anotherNumberList = {5, 6, 10, 12, 14, 44, 67, 87, 205, 103};

    for (int number: anotherNumberList) {
        std::cout << number << ' ';
    }

    std::cout << std::endl;

    anotherNumberList.erase(std::remove(anotherNumberList.begin(), anotherNumberList.end(), 12),
                            anotherNumberList.end());

    for (int number: anotherNumberList) {
        std::cout << number << ' ';
    }

}
