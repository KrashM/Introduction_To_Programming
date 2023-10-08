#include <iostream>
#include <iomanip>

int main() {
    // Set precision to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Output floating point numbers with padding and alignment
    std::cout << std::setw(10) << std::left << 3.14159 << std::endl;
    std::cout << std::setw(10) << std::right << 2.71828 << std::endl;

    // Output integers with padding and leading zeros
    std::cout << std::setw(10) << std::setfill('0') << std::left << 42 << std::endl;
    std::cout << std::setw(10) << std::setfill('0') << std::right << 123 << std::endl;

    // Output boolean values as "true" or "false" (otherwise printed as 1 or 0)
    std::cout << std::boolalpha << true << std::endl;
    std::cout << std::boolalpha << false << std::endl;

    return 0;
}
