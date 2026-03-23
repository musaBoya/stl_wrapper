#ifndef WRAPPER_ARRAY_HPP
#define WRAPPER_ARRAY_HPP

#include <iostream>
#include <array>
#include <stdexcept>
#include <string>

template <typename T, std::size_t N>
class array_s {
private:
    std::array<T, N> _internal_data;

public:
    array_s(std::initializer_list<T> list) {
        std::size_t i = 0;
        for (auto& item : list) {
            if (i < N) _internal_data[i++] = item;
        }
    }
    
    T& operator[](std::size_t index) {
        if (index >= N) {
            throw std::out_of_range(std::to_string(index) + " indeksi gecersiz! Maksimum: " + std::to_string(N-1));
        }
        return _internal_data[index];
    }

    constexpr std::size_t size() const { return N; }
};
#endif