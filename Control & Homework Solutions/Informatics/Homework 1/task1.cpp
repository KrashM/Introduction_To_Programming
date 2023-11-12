#include <iostream>
#include <cmath>

int main()
{
    const double EPS = 0.001;
    const double r = 4;
    const double By = sqrt(7);
    const double Cy = sqrt(7);

    double x, y;
    std::cin >> x >> y;

    const double equation = x * x + y * y, distance = r * r;

    if(std::abs(equation - distance) < EPS ||                                       // x * x + y * y = r * r
       (x == 0 && y >= -6 && y <= 6) ||                                             // QJ
       (std::abs(y) < By && (std::abs(x - 3) < EPS || std::abs(x + 3) < EPS)) ||    // BA; CD
       (x >= -2 && x <= 2 && std::abs(y + 6) < EPS) ||                              // HE
       (x >= -2 && x <= 2 && std::abs(y + 7) < EPS) ||                              // GP
       (y >= -7 && y <= -6 && std::abs(x - 2) < EPS) ||                             // EP
       (y >= -7 && y <= -6 && std::abs(x + 2) < EPS) ||                             // HG
       (x >= -1 && x <= 1 && std::abs(y - 5) < EPS) ||                              // FI
       (std::abs(By * x + 3 * y) < EPS) ||                                          // BD
       (std::abs(Cy * x - 3 * y) < EPS && x < 0))                                   // CO  
    {
        std::cout << "On the edge" << std::endl;
        return 0;
    }

    if((x > -2 && x < 2) && (y < -6 && y > -7))
    {
        std::cout << "Grey" << std::endl;
        return 0;
    }

    if(equation > distance)
    {
        std::cout << "Outside" << std::endl;
        return 0;
    }    

    // Inside the circle
    if(x > 3)
    {
        std::cout << "Purple" << std::endl;
        return 0;
    }

    if(x < -3)
    {
        std::cout << "Outside" << std::endl;
        return 0;
    }

    if((x > -3 && x < 0) && (Cy * x - 3 * y < 0) && (By * x + 3 * y < 0))
    {
        std::cout << "Pink" << std::endl;
        return 0;
    }

    if(x > -3 && x < 0 && y < 0)
    {
        std::cout << "Blue" << std::endl;
        return 0;
    }

    if(x > -3 && x < 0 && y > 0)
    {
        std::cout << "Red" << std::endl;
        return 0;
    }

    if(x > 0 && x < 3 && (By * x - 3 * y < 0))
    {
        std::cout << "Green" << std::endl;
        return 0;
    }

    std::cout << "Yellow" << std::endl;

    return 0;
}
