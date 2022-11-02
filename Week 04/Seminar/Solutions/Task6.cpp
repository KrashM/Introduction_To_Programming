#include <iostream>
#include <cmath>

double distance(const int &x1, const int &y1, const int &x2, const int &y2){

    double result = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    unsigned int temp = result * 1000;
    result = temp / 1000.0;

    return result;

}

int main(){

    unsigned int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    std::cout << distance(x1, y1, x2, y2) + distance(x1, y1, x3, y3) + distance(x2, y2, x3, y3) << '\n';

}