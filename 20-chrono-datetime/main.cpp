#include <iostream>
#include <chrono>

int main() {
    // DURATION
    std::chrono::seconds seconds(10);
    std::chrono::minutes minutes(2);
    std::chrono::hours hours(3);

    std::cout << hours.count() << "hours " << minutes.count() << "minutes " << seconds.count() << "seconds.";

    std::cout << std::endl;

    // TIME POINT
    // std::chrono::system_clock: Represents the system-wide real time wall clock.
    // std::chrono::steady_clock: Represents a monotonic clock that is guaranteed to never be adjusted.
    // std::chrono::high_resolution_clock: Represents the clock with the shortest tick period.

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count();


    std::cout << std::endl;

    // CLOCK
    // time_point: A specific point in time.
    // duration: The time duration between two time points.
    // timePointOfNow(): A static function that returns the current time point.

    // Get the time_point 1 hour from timePointOfNow
    std::chrono::system_clock::time_point one_hour_from_now = now + std::chrono::hours(1);



    // CONVERTING TIME POINTS TO CALENDAR TIME
    std::chrono::system_clock::time_point timePointOfNow = std::chrono::system_clock::now();
    std::time_t nowC = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&nowC) << std::endl;

    return 0;
}
