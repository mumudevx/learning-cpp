#include <iostream>

struct Weather {
    int lowest;
    int highest;
};

// Unions are used to store different data types in the same memory location.
union Data {
    int number;
    char letter;
    float price;
};

int main() {
    Data anyData{};
    anyData.number = 33;
    anyData.letter = 'A';
    anyData.price = 13.5f;

    Data *pointerOfAnyData = &anyData;
    int *pointerOfNumber = &anyData.number;
    char *pointerOfLetter = &anyData.letter;
    float *pointerOfPrice = &anyData.price;

    std::cout << "anyData Ref: " << &anyData << std::endl;
    std::cout << "Pointer anyData: " << pointerOfAnyData << std::endl;
    std::cout << "Pointer number: " << pointerOfNumber << std::endl;
    std::cout << "Pointer letter: " << pointerOfLetter << std::endl;
    std::cout << "Pointer price: " << pointerOfPrice << std::endl;


    std::cout << "------------------" << std::endl;

    Weather todayWeather{18, 37};

    Weather *pointerOfTodayWeather = &todayWeather;
    int *pointerOfLowest = &todayWeather.lowest;
    int *pointerOfHighest = &todayWeather.highest;

    std::cout << "weather Ref: " << &todayWeather << std::endl;
    std::cout << "Pointer lowest: " << pointerOfLowest << std::endl;
    std::cout << "Pointer highest: " << pointerOfHighest << std::endl;
}
