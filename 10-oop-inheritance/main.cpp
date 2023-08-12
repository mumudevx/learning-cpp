#include <iostream>

class Animal {
public:
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Bark bark!" << std::endl;
    }
};

int main() {

    Dog myDog;
    myDog.breathe();
    myDog.bark();

    return 0;
}
