#include <array>
#include <iostream>
#include <stdexcept>

#include "wrapped_array.hpp"

int main() {
    std::cout << "the world is yours";
    array_s<int, 3> myarr{2, 34, 2};

    for (std::size_t i = 0; i < myarr.size(); ++i) {
        std::cout << " -> " << myarr[i] << "\n";
    }

    try {
        std::cout << " -> " << myarr.at(3) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "caught exception: " << e.what() << "\n";
    }

    std::array intarr{1, 23, 4};
    for (std::size_t i = 0; i < intarr.size(); ++i) {
        std::cout << " -> " << intarr[i] << "\n";
    }
}
