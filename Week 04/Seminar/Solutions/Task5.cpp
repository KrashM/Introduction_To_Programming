#include <iostream>
#include <cmath>

double distance(const int &x1, const int &y1, const int &x2, const int &y2){

    double result = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    unsigned int temp = result * 1000;
    result = temp / 1000.0;

    return result;

}

int main(){

    unsigned int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << distance(x1, y1, x2, y2) << '\n';

}