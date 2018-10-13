#include <iostream>
#include <chrono>
#include <thread>

#include "utils/void.h"

namespace chrono = std::chrono;

// returns a pair with:
//     [0] -> function result
//     [1] -> execution time
template <class Fun, class... Args>
auto record_time(Fun&& fun, Args&&... args) {
    // start recording time
    auto beginTime = chrono::system_clock::now();

    // invoke function and get result
    auto funResult = utl::void_invoke(std::forward<Fun>(fun),
                                      std::forward<Args>(args)...);

    // stop recording time and get elapsed time
    auto endTime = chrono::system_clock::now();
    auto elapsedTime = endTime - beginTime;

    // return needed data
    return std::make_pair(funResult, elapsedTime);
}

int main() {
    auto info = record_time([] {
        std::this_thread::sleep_for(chrono::seconds(1));
        // returns nothing... void_type should be triggered and
        // printed down below
    });

    std::cout << "execution time: "
              << chrono::duration_cast<chrono::seconds>(info.second).count()
              << "\nreturn value: "
              << info.first << "\n";

    return 0;
}
