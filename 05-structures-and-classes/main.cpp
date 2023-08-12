#include <iostream>
#include <utility>

using namespace std;

struct Flower {
    string name;
    string family;
    string siteType;
};

class Person {
private:
    string _fullName;
    int _age;

public:
    explicit Person(string fullName, int age) {
        _fullName = std::move(fullName);
        _age = age;
    }

public:
    void Introduce() {
        std::cout << "Hello! " << "My name is " << this->_fullName << " I'm " << this->_age << " years old.";
    }
};

int main() {
    Flower dwarf = Flower{"Dwarf gentians", "Gentianaceae", "Wet meadows, bogs"};
    std::cout << "Name: " << dwarf.name << std::endl;
    std::cout << "Family: " << dwarf.family << std::endl;
    std::cout << "Site Type: : " << dwarf.siteType << std::endl;

    std::cout << "---------------------" << std::endl;

    Person someOne = Person("Cristiana Owls", 24);
    someOne.Introduce();

    return 0;
}
