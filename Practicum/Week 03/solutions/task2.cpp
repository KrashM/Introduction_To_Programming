#include <iostream>

int main(){

    short a;
    std::cin >> a;

    if(a < 0 || a > 255){

        std::cout << "Invalid value\n";
        return 0;

    }

    int toggledBitsCount = 0;
    toggledBitsCount += !!(a & 1 << 0);
    toggledBitsCount += !!(a & 1 << 1);
    toggledBitsCount += !!(a & 1 << 2);
    toggledBitsCount += !!(a & 1 << 3);
    toggledBitsCount += !!(a & 1 << 4);
    toggledBitsCount += !!(a & 1 << 5);
    toggledBitsCount += !!(a & 1 << 6);
    toggledBitsCount += !!(a & 1 << 7);

    std::cout << "The number: " << a << " has " << (toggledBitsCount % 2 ? "odd" : "even") << " number of bits set.\n";

}