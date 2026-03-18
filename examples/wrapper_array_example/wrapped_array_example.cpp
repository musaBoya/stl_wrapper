#include "wrapped_array.hpp"

int main(){
    std::cout << "the world is yours";
    array_s<int,3> myarr{2,34,2};

    for (int i = 0; i<4;++i){
        std::cout << " -> " << myarr[i] << "\n";
    }

    std::array intarr{1,23,4};
    for (int i = 0; i<4;++i){
        std::cout << " -> " << intarr[i] << "\n";
    }
}