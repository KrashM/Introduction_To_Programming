#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if(a <= 0 || b <= 0 || c <= 0)
    {
        std::cout << "Incorrect input." << std::endl;
        return 1;
    }

    if(a + b <= c || b + c <= a || a + c <= b)
    {
        std::cout << "These sides can't form a triangle." << std::endl;
    }
    else if(a == b && b == c)
    {
        std::cout << "These sides can form a triangle. The triangle is equilateral." << std::endl;
    }
    else if(a == b || b == c || a == c)
    {
        std::cout << "These sides can form a triangle. The triangle is isosceles." << std::endl;
    }
    else
    {
        std::cout << "These sides can form a triangle. The triangle is scalene." << std::endl;
    }
    
    return 0;
}
