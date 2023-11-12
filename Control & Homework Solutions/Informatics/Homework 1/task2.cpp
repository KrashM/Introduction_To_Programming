#include <iostream>

int main() {
    const unsigned mask1 = (1 << 6) - 1; // 111111 for minutes and seconds
    const unsigned mask2 = (1 << 4) - 1; // 1111 for hour_s
    const unsigned mask3 = (1 << 2) - 1; // 11 for hour_f
    const unsigned mask4 = 1; // 1 for day_format

    unsigned number;
    std::cin >> number;
    
    // -- Seconds --
    const unsigned seconds = number & mask1;
    number >>= 6;

    if (seconds > 59)
    {
        std::cout << seconds << " is not a valid value for seconds!" << std::endl;
        return -1;
    }

    // -- Minutes --
    const unsigned minutes = number & mask1;
    number >>= 6;

    if (minutes > 59)
    {
        std::cout << minutes << " is not a valid value for minutes!" << std::endl;
        return -1;
    }

    // -- First digit of the hours --
    const unsigned hour_s = number & mask2;
    number >>= 4;

    if (hour_s > 9)
    {
        std::cout << "Invalid second hour digit value!" << std::endl;
        return -1;
    }

    // -- Second digit of the hours --
    const unsigned hour_f = number & mask3;
    number >>= 2;

    if (hour_f > 2)
    {
        std::cout << "Invalid first hour digit value!" << std::endl;
        return -1;
    }
    
    // -- Exact hours --
    const unsigned hh = hour_f * 10 + hour_s;
    
    if (hh >= 24)
    {
        std::cout << hh << " is not a valid value for hours!" << std::endl;
        return -1;
    }

    // -- Day format --
    const bool is_24_hour_format = (number & mask4) ? true : false;

    if (!is_24_hour_format && hh > 12)
    {
        std::cout << hh << " is not a valid value for a 12 hour format!" << std::endl;
        return -1;
    }

    // -- Printing the result --
    std::cout << (hh < 10 ? "0" : "") << hh << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << std::endl;
    
   return 0;
}