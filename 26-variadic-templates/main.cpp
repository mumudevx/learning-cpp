#include <iostream>

// Base case for recursion
template<typename T>
T sum(T t) {
    return t;
}

// Variadic Template
template<typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

// Tuple
template<typename... Types>
class Tuple;

// Base case: empty tuple
template<>
class Tuple<> {
};

// Recursive Case: Tuple with one or more elements
template<typename Head, typename... Tail>
class Tuple<Head, Tail...> : public Tuple<Tail...> {
public:
    Tuple(Head head, Tail... tail) : Tuple<Tail...>(tail...), head_(head) {}

    Head head() const { return head_; }

private:
    Head head_;
};


int main() {
    // Recursion
    int result = sum(1, 2, 3, 4, 5);
    std::cout << "The sum is: " << result << std::endl;

    // Tuple
    Tuple<int, float, double> myTuple(3, 2.0f, 5.7);
    std::cout << "First element of tuple: " << myTuple.head() << std::endl;

    return 0;
}
