#ifndef WRAPPER_ARRAY_HPP
#define WRAPPER_ARRAY_HPP

#include <array>
#include <initializer_list>
#include <stdexcept>
#include <string>

template <typename T, std::size_t N>
class array_s {
private:
    std::array<T, N> _internal_data{};

public:
    array_s(std::initializer_list<T> list) {
        std::size_t i = 0;
        for (const auto& item : list) {
            if (i < N) {
                _internal_data[i++] = item;
            }
        }
    }

    T& operator[](std::size_t index) {
        return _internal_data[index];
    }

    const T& operator[](std::size_t index) const {
        return _internal_data[index];
    }

    T& at(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("array_s::at - index out of range");
        }
        return _internal_data[index];
    }

    const T& at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("array_s::at - index out of range");
        }
        return _internal_data[index];
    }

    constexpr std::size_t size() const { return N; }
};
#endif
