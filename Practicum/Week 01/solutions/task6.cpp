#include <iostream>

int main()
{
    int int1, int2;
    double double1, double2;
    float float1, float2;

    std::cout << "Enter two integers: ";
    std::cin >> int1 >> int2;
    std::cout << "Enter two double numbers: ";
    std::cin >> double1 >> double2;
    std::cout << "Enter two float numbers: ";
    std::cin >> float1 >> float2;

    std::cout << "\n-------Operations between integers-------" << std::endl;
    std::cout << int1 << " + " << int2 << " = " << int1 + int2 << std::endl;
    std::cout << int1 << " - " << int2 << " = " << int1 - int2 << std::endl;
    std::cout << int1 << " * " << int2 << " = " << int1 * int2 << std::endl;
    std::cout << int1 << " % " << int2 << " = " << int1 % int2 << std::endl;
    std::cout << int1 << " / " << int2 << " = " << int1 / int2 << std::endl;

    std::cout << "\n-------Operations between doubles-------" << std::endl;
    std::cout << double1 << " + " << double2 << " = " << double1 + double2 << std::endl;
    std::cout << double1 << " - " << double2 << " = " << double1 - double2 << std::endl;
    std::cout << double1 << " * " << double2 << " = " << double1 * double2 << std::endl;
    // std::cout << double1 << " % " << double2 << " = " << double1 % double2 << std::endl; // --> error
    std::cout << double1 << " / " << double2 << " = " << double1 / double2 << std::endl;

    std::cout << "\n-------Operations between floats-------" << std::endl;
    std::cout << float1 << " + " << float2 << " = " << float1 + float2 << std::endl;
    std::cout << float1 << " - " << float2 << " = " << float1 - float2 << std::endl;
    std::cout << float1 << " * " << float2 << " = " << float1 * float2 << std::endl;
    // std::cout << float1 << " % " << float2 << " = " << float1 % float2 << std::endl; // --> error
    std::cout << float1 << " / " << float2 << " = " << float1 / float2 << std::endl;

    std::cout << "\n-----------Mixed operations------------" << std::endl;
    std::cout << int1 << " + " << double1 << " = " << int1 + double1 << std::endl;
    std::cout << int1 << " + " << float1 << " = " << int1 + float1 << std::endl;
    std::cout << double1 << " + " << float1 << " = " << double1 + float1 << std::endl;

    std::cout << int1 << " - " << double1 << " = " << int1 - double1 << std::endl;
    std::cout << int1 << " - " << float1 << " = " << int1 - float1 << std::endl;
    std::cout << double1 << " - " << float1 << " = " << double1 - float1 << std::endl;

    std::cout << int1 << " * " << double1 << " = " << int1 * double1 << std::endl;
    std::cout << int1 << " * " << float1 << " = " << int1 * float1 << std::endl;
    std::cout << double1 << " * " << float1 << " = " << double1 * float1 << std::endl;

    std::cout << int1 << " / " << double1 << " = " << int1 / double1 << std::endl;
    std::cout << double1 << " / " << int1 << " = " << double1 / int1 << std::endl;
    std::cout << int1 << " / " << float1 << " = " << int1 / float1 << std::endl;
    std::cout << float1 << " / " << int1 << " = " << float1 / int1 << std::endl;
    std::cout << double1 << " / " << float1 << " = " << double1 / float1 << std::endl;

    // std::cout << int1 << " % " << float1 << " = " << int1 % float1 << std::endl; // --> error
    // std::cout << float1 << " % " << int1 << " = " << float1 % int1 << std::endl; // --> error
    
    return 0;
}
