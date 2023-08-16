#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "Nam nam nam" << std::endl;
    }
};

class Mammal {
public:
    void breath() {
        std::cout << "Breathing..." << std::endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        std::cout << "Woof, woof!" << std::endl;
    }
};

int main() {
    Dog dog;

    dog.eat();
    dog.breath();
    dog.bark();

    return 0;
}
