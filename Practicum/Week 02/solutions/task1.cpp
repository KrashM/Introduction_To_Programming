#include <iostream>

int main() {

    double alpha, beta, gamma;
    std::cin >> alpha >> beta >> gamma;

    if(alpha <= 0 || beta <= 0 || gamma <= 0)
    {
        std::cout << "Incorrect input." << std::endl;
        return -1;
    }

    const double EPS = 0.001,
                 ANGLES_SUM = 180;

    std::cout << ( (std::abs(alpha + beta + gamma - ANGLES_SUM) < EPS) ? "These angles can form a triangle" :  "These angles can't form a triangle") << std::endl;
    
}

