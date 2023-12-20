#include <iostream>
#include <cmath>

double Distance(int const x1, int const y1, int const x2, int const y2){
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool IsInsideCircle(int const x, int const y, int const r, int const x2, int const y2){
    return Distance(x, y, x2, y2) <= r;
}

int main(){

    double const EPSILON = 0.001;
    int x1, x2, y1, y2, r1, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double const distance = Distance(x1, y1, x2, y2);

    if(std::abs(distance - (r1 + r2)) > EPSILON) std::cout << "Circles have no common points\n";
    else if(std::abs(distance - (r1 + r2)) < EPSILON) std::cout << "Circles are touching\n";
    else if(IsInsideCircle(x1, y1, r1, x2, y2)  && distance - r1 > EPSILON) std::cout << "Circle 2 is inside circle 1\n";
    else if(IsInsideCircle(x2, y2, r2, x1, y1) && distance - r2 > EPSILON) std::cout << "Circle 1 is inside circle 2\n";
    else std::cout << "Circles are overlapping\n";

    return 0;

}