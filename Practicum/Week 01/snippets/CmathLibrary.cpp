#include <iostream>
#include <cmath>

int main() {
    
    float a = INFINITY; // Infinity for floats  
    float b = NAN; // Not a number 

    //min and max
    int first = 5, second = 28;
    std::cout << "min: " << std::min(first, second) << " " << "max: " << std::max(first, second) << std::endl;
    
    //square root
    std::cout << "sqrt(2) = " << sqrt(2) << std::endl;

    //power
    std::cout << "pow(2, 3) = " << pow(2, 3) << std::endl;

    //absolute value
    std::cout << "abs(-2) = " << abs(-2) << std::endl;

    //rounding
    std::cout << "round(2.3) = " << round(2.3) << std::endl;

    //floor
    std::cout << "floor(2.3) = " << floor(2.3) << std::endl;

    //ceiling
    std::cout << "ceil(2.3) = " << ceil(2.3) << std::endl;

    //logarithm
    std::cout << "log(2.3) = " << log(2.3) << std::endl;

    //log10
    std::cout << "log10(2.3) = " << log10(2.3) << std::endl;
    return 0;
}