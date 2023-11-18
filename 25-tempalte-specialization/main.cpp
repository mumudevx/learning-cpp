#include <iostream>

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(char first, char second) : first(first), second(second) {
        this->first = std::toupper(this->first);
        this->second = std::toupper(this->second);
    }
};

int main() {
    Pair<char, char> charPair('a', 'b');

    std::cout << charPair.first << " " << charPair.second << std::endl;

    return 0;
}
