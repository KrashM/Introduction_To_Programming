#include <iostream>
#include <cmath>

size_t const NUMBER_OF_SIDES_OF_RECTANGLE = 4;
unsigned const MAXIMUM_NUMBER_OF_POINTS = 2'000'000'000;

double const PI = 3.14;
double const EPSILON = 0.01;
double const DISTANCE_MULTIPLIER = (PI / 2 + 1) / 2;

double const X_BOUND = 5;
double const Y_BOUND = 2;
double const sides[NUMBER_OF_SIDES_OF_RECTANGLE] = { -X_BOUND, -Y_BOUND, X_BOUND, Y_BOUND };

unsigned Pow(unsigned const n, unsigned const power){

    unsigned result = 1;
    for(unsigned i = 0; i < power; ++i) result *= n;
    return result;

}

double RoundToNumberOfDigits(double number, unsigned const numberOfDigitsAfterComma){

    unsigned powerOfTen = Pow(10, numberOfDigitsAfterComma);

    number *= powerOfTen;
    number = (long long) number;
    number /= powerOfTen;

    return number;

}

bool IsOutside(double const x, double const y){
    return x + X_BOUND < EPSILON || EPSILON < x - X_BOUND || y + Y_BOUND < EPSILON || EPSILON < y - Y_BOUND;
}

double EuclideanDistance(double const x1, double const y1, double const x2, double const y2){
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double FunctionToCalculateDistance(double const distance){
    return DISTANCE_MULTIPLIER * distance;
}

double CalculateIntersectX(double const lineSlope, double const lineIntercept, double const value){
    return (value - lineIntercept) / lineSlope;
}

double CalculateIntersectY(double const lineSlope, double const lineIntercept, double const value){
    return lineSlope * value + lineIntercept;
}

void FindIntersection(double const insidePointX, double const insidePointY, double &outsidePointX, double &outsidePointY){

    if(outsidePointX == insidePointX){

        outsidePointY = outsidePointY + Y_BOUND < EPSILON ? -Y_BOUND : Y_BOUND;
        return;

    }

    double intersectPointX, intersectPointY, lineSlope, lineIntercept;

    lineSlope = (outsidePointY - insidePointY) / (outsidePointX - insidePointX);
    lineIntercept = insidePointY - lineSlope * insidePointX;

    for(unsigned i = 0; i < NUMBER_OF_SIDES_OF_RECTANGLE; ++i){

        if(i % 2){

            intersectPointX = CalculateIntersectX(lineSlope, lineIntercept, sides[i]);
            intersectPointY = sides[i];

        }
        else{

            intersectPointX = sides[i];
            intersectPointY = CalculateIntersectY(lineSlope, lineIntercept, sides[i]);

        }

        if(!IsOutside(intersectPointX, intersectPointY) && EuclideanDistance(intersectPointX, intersectPointY, outsidePointX, outsidePointY) < EuclideanDistance(insidePointX, insidePointY, outsidePointX, outsidePointY)){

            outsidePointX = intersectPointX;
            outsidePointY = intersectPointY;

            return;

        }

    }

}

double ProcessTwoPoints(double fromPointX, double fromPointY, double toPointX, double toPointY, bool &isOutside){

    if(IsOutside(toPointX, toPointY)){

        if(isOutside) return 0;

        FindIntersection(fromPointX, fromPointY, toPointX, toPointY);
        isOutside = true;

    }
    else if(isOutside){

        FindIntersection(toPointX, toPointY, fromPointX, fromPointY);
        isOutside = false;

    }

    return FunctionToCalculateDistance(EuclideanDistance(fromPointX, fromPointY, toPointX, toPointY));

}

int main() {

    double fromPointX, fromPointY, toPointX, toPointY, totalDistance = 0;
    bool isOutside = false;
    unsigned n;

    std::cin >> n;

    if(!n || n > MAXIMUM_NUMBER_OF_POINTS){

        std::cout << "Invalid value for n\n";
        return -1;

    }

    std::cin >> fromPointX >> fromPointY;
    isOutside = IsOutside(fromPointX, fromPointY);

    for(unsigned i = 1; i < n; ++i){

        std::cin >> toPointX >> toPointY;

        totalDistance += ProcessTwoPoints(fromPointX, fromPointY, toPointX, toPointY, isOutside);

        fromPointX = toPointX;
        fromPointY = toPointY;

    }

    std::cout << RoundToNumberOfDigits(totalDistance, 3) << '\n';

    return 0;

}