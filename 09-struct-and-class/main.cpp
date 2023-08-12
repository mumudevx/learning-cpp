#include <iostream>
#include <utility>

struct Student {
    int id;
    std::string name;
};

class Car {
    std::string brand;
    int year;

public:
    Car(std::string b, int y) : brand(std::move(b)), year(y) {}

    void DisplayInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

int main() {

    Student student;
    student.id = 1;
    student.name = "Michella";

    std::cout << "Student's Id: " << student.id << std::endl;
    std::cout << "Student's Name: " << student.name << std::endl;

    auto myCar = Car("Mustang", 1990);
    myCar.DisplayInfo();

    return 0;
}
