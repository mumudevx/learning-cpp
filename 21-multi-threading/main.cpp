#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void my_function() {
    std::cout << "This function is executing in seperated thread" << std::endl;
}

void print_sum(int a, int b) {
    std::cout << "The sum is: " << a + b << std::endl;
}

void print_block(int n, char c) {
    std::unique_lock<std::mutex> locker(mtx);

    for (int i = 0; i < n; ++i) {
        std::cout << c;
    }

    std::cout << std::endl;
}

int main() {
    // Create thread with function
    std::thread thread(my_function);
    thread.join();

    // Thread with arguments
    std::thread threadWithArguments(print_sum, 3, 7);
    threadWithArguments.join();

    // Mutex and Lock
    std::thread threadOne(print_block, 50, '*');
    std::thread threadTwo(print_block, 50, '$');

    threadOne.join();
    threadTwo.join();

    return 0;
}
