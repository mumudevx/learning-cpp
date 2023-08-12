#include <iostream>

// Forward Declaration For a Class
class MyClass;

void UseMyClass(MyClass* ptr);

class MyClass {
public:
    int data;
    MyClass(int d) : data(d) {}
};

void UseMyClass(MyClass* ptr) {
    std::cout << ptr->data << std::endl;
}


// Forward Declaration For a Function
void SomeFunction(int value);

class AnotherClass {
public:
    void CallSomeFunction(int x) {
        SomeFunction(x);
    }
};

void SomeFunction(int value) {
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    auto myClass = MyClass(44);
    UseMyClass(&myClass);

    auto anotherClass = AnotherClass();
    anotherClass.CallSomeFunction(2);

    return 0;
}
