#include <iostream>
#include <type_traits>

// Composing Type Traits
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type find_max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int z;
    int *z_ptr = &z;

    std::cout << "Is 'z' a pointer? " << std::boolalpha << std::is_pointer<decltype(z)>::value << std::endl;
    std::cout << "Is 'z_ptr' a pointer? " << std::boolalpha << std::is_pointer<decltype(z_ptr)>::value << std::endl;

    std::cout << "---------------" << std::endl;

    // Composing Type Traits
    int max = find_max(10, 20);
    std::cout << "Max: " << max << std::endl;
    std::cout << "Max: " << find_max('a', 'b') << std::endl;

    return 0;
}
