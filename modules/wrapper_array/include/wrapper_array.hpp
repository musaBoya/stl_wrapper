#ifndef WRAPPER_ARRAY_H
#define WRAPPER_ARRAY_H

#include <iostream>
#include <array>
#include <stdexcept>

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
            
            std::cerr << "Hata: " << index << " indeksi gecersiz! Maksimum: " << N-1 << std::endl;
            return _internal_data[0]; // Şimdilik ilk elemanı döndürelim (Dummy)
        }
        return _internal_data[index];
    }

    constexpr std::size_t size() const { return N; }
};
#endif