#include <iostream>
#include <variant>
#include <vector>

class Shape {
public:
    virtual void Draw() {
        std::cout << "Shape is drawing..." << std::endl;
    }
};

class Circle : public Shape {
public:
    void Draw() override {
        std::cout << "Circle is drawing..." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void Draw() override {
        std::cout << "Rectangle is drawing..." << std::endl;
    }
};


int main() {
    using MultiType = std::variant<Shape, Circle, Rectangle>;
    std::vector<MultiType> shapes;

    shapes.emplace_back(Shape());
    shapes.emplace_back(Circle());
    shapes.emplace_back(Rectangle());

    for (auto &variant: shapes) {
        if (std::holds_alternative<Shape>(variant)) {
            auto shape = std::get<Shape>(variant);
            shape.Draw();
        } else if (std::holds_alternative<Circle>(variant)) {
            auto shape = std::get<Circle>(variant);
            shape.Draw();
        } else if (std::holds_alternative<Rectangle>(variant)) {
            auto shape = std::get<Rectangle>(variant);
            shape.Draw();
        }
    }

    return 0;
}
