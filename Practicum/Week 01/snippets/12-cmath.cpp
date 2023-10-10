#include <iostream>
#include <cmath>

int main() {
    
    float a = INFINITY; // Infinity for floats  
    float b = NAN; // Not a number 

    // Min and Max
    int first = 5, second = 28;
    std::cout << "min: " << std::min(first, second) << " " << "max: " << std::max(first, second) << std::endl;
    
    // Square root
    std::cout << "sqrt(2) = " << sqrt(2) << std::endl;

    // Power
    std::cout << "pow(2, 3) = " << pow(2, 3) << std::endl;

    // Absolute value
    std::cout << "abs(-2) = " << abs(-2) << std::endl;

    // Rounding
    std::cout << "round(2.3) = " << round(2.3) << std::endl;

    // Floor
    std::cout << "floor(2.3) = " << floor(2.3) << std::endl;

    // Ceiling
    std::cout << "ceil(2.3) = " << ceil(2.3) << std::endl;

    // Logarithm
    std::cout << "log(2.3) = " << log(2.3) << std::endl;

    // Log10
    std::cout << "log10(2.3) = " << log10(2.3) << std::endl;
    return 0;
}