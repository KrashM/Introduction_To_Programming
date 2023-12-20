#include <iostream>
#include <cmath>

double Distance(int const x1, int const y1, int const x2, int const y2){
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool HasPointInsideCircle(int const x, int const y, int const radius, int const x2, int const y2, int const a){
    return Distance(x, y, x2, y2) <= radius || Distance(x, y, x2 + a, y2) <= radius || Distance(x, y, x2, y2 + a) <= radius || Distance(x, y, x2 + a, y2 + a) <= radius;
}

bool IsInsideSuqare(int const x, int const y, int const a, int const x2, int const y2, int const radius){
    return x <= x2 && x2 <= x + a && y <= y2 && y2 <= y + a && x <= x2 - radius && x2 + radius <= x + a && y <= y2 - radius && y2 + radius <= y + a;
}

bool IsTouchingSide(int const x, int const y, int const a, int const x2, int const y2, int const radius){
    return x2 + radius == x && y <= y2 && y2 <= y + a ||
        x2 - radius == x + a && y <= y2 && y2 <= y + a ||
        y2 + radius == y && x <= x2 && x2 <= x + a ||
        y2 - radius == y + a && x <= x2 && x2 <= x + a;
}

bool IsOverlappingOnTheSide(int const x, int const y, int const a, int const x2, int const y2, int const radius){
    return x2 + radius > x && y <= y2 && y2 <= y + a ||
        x2 - radius < x + a && y <= y2 && y2 <= y + a ||
        y2 + radius > y && x <= x2 && x2 <= x + a ||
        y2 - radius < y + a && x <= x2 && x2 <= x + a;
}

int main(){

    double const EPSILON = 0.001;
    int circleX, squareX, circleY, squareY, radius, a;
    std::cin >> circleX >> circleY >> radius >> squareX >> squareY >> a;

    double distance = Distance(circleX, circleY, squareX, squareY);
    double greatestDistance = distance, smallestDistance = distance;

    distance = Distance(circleX, circleY, squareX + a, squareY);
    if(greatestDistance < distance) greatestDistance = distance;
    if(smallestDistance > distance) smallestDistance = distance;

    distance = Distance(circleX, circleY, squareX, squareY + a);
    if(greatestDistance < distance) greatestDistance = distance;
    if(smallestDistance > distance) smallestDistance = distance;

    distance = Distance(circleX, circleY, squareX + a, squareY + a);
    if(greatestDistance < distance) greatestDistance = distance;
    if(smallestDistance > distance) smallestDistance = distance;

    if(IsInsideSuqare(squareX, squareY, a, circleX, circleY, radius)) std::cout << "Circle is inside square\n";
    else if(radius - greatestDistance > EPSILON) std::cout << "Square is inside circle\n";
    else if(std::abs(radius - smallestDistance) < EPSILON || IsTouchingSide(squareX, squareY, a, circleX, circleY, radius)) std::cout << "Both are touching\n";
    else if(HasPointInsideCircle(circleX, circleY, radius, squareX, squareY, a) || IsOverlappingOnTheSide(squareX, squareY, a, circleX, circleY, radius)) std::cout << "Overlapping\n";
    else std::cout << "Nothing in common\n";

    return 0;

}