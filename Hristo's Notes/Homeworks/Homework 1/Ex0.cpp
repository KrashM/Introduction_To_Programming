#include <iostream>
#include <cmath>
using namespace std;

struct point{
    
    double x, y;
    
    // Конструктурите ще ги разглеждаме по ООП
    // Само знайте че задават стойностите
    point(double x, double y){
        
        this -> x = x;
        this -> y = y;
        
    }
    point(){}
    
};

void getAreaOfPoint(const point &myPoint);

int main(){

    // Test for the program
    // Should give:
    // Purple
    // Green
    // Pink
    // Red
    // Yellow
    // Green
    // Blue
    // Red
    // Yellow
    // Green
    // Yellow
    // Yellow
    // Yellow
    // None
    // Pink
    // None
    // None
    // None
    // None
    // None
    // Green
    // double x[] = { 3.00, 1.25, -2.38, -2.23, 1.53, 1.70, -0.70, -0.16, 2.03, 0.98, 2.66, 0.20, 2.46, -2.96, -2.50, 2, 0, 0, 2.828, -2.828, 1.097 };
    // double y[] = { 0.02, 3.37, -1.41, 3.06, -3.10, 3.29, -2.78, 0.46, 1.31, 1.30, -0.19, 0.19, 0.14, -0.60, -1.86, 2, 2.734, -2.552, -1.159, 1.026, 3.846 };

    // for(unsigned i = 0; i < sizeof(x) / sizeof(double); i++) getAreaOfPoint(point(x[i], y[i]));

    point myPoint;
    cin >> myPoint.x >> myPoint.y;

    getAreaOfPoint(myPoint);

}

double pow(double num, unsigned power){

    if(power == 1) return num;
    return num * pow(num, power - 1);

}

// Разстояние от (0, 0)
double distFromOrigin(const point &myPoint){
    return sqrt(pow(myPoint.x, 2) + pow(myPoint.y, 2));
}

// Закръгляне до 3тия знак на десетичната запетая.
// За жалост ми бяха казали, че не мога да ползвам iomanip библиотеката(std::setprecision).
double roundToThreeDigits(double n){

    const int whole = (int)n;
    return (int)((n - whole) * 1000) / 1000.0 + whole;

}

void getAreaOfPoint(const point &myPoint){

    const double specialPoint = roundToThreeDigits(2 * sqrt(2));

    if(myPoint.x > -2 && myPoint.x < 2 && myPoint.y > -7 && myPoint.y < -6) cout << "Gray\n";
    else if(distFromOrigin(myPoint) >= 4) cout << "Point is outside of everything\n";
    else if(myPoint.x > 0){

        if(roundToThreeDigits(myPoint.y / myPoint.x) > 1) cout << "Green\n";
        else if(myPoint.x > specialPoint) cout << "Purple\n";
        else if(myPoint.x < specialPoint && (roundToThreeDigits(myPoint.y / myPoint.x) < 1 || myPoint.y < 0)) cout << "Yellow\n";
        else cout << "Point is on a border\n";

    }
    else if(myPoint.x > -specialPoint){

        if(myPoint.x == 0) cout << "Point is on a border\n";

        else if(myPoint.y > 0){

            if(roundToThreeDigits(myPoint.y / myPoint.x) < -1) cout << "Red\n";
            else if(roundToThreeDigits(myPoint.y / myPoint.x) > -1) cout << "Pink\n";
            else cout << "Point is on a border\n";

        }
        else{

            if(roundToThreeDigits(myPoint.y / myPoint.x) < 1) cout << "Pink\n";
            else if(roundToThreeDigits(myPoint.y / myPoint.x) > 1) cout << "Blue\n";
            else cout << "Point is on a border\n";

        }

    }
    else cout << "Point is on a border\n";
    
}

/*
3.00 0.02 - Purple
1.25 3.37 - Green
-2.38 -1.41 - Pink
-2.23 3.06 - Red
1.53 -3.10 - Yellow
1.70 3.29 - Green
-0.70 -2.78 - Blue
-0.16 0.46 - Red
2.03 1.31 - Yellow
0.98 1.30 - Green
2.66 -0.19 - Yellow
0.20 0.19 - Yellow
2.46 0.14 - Yellow
-2.96 -0.60 - None
-2.50 -1.86 - Pink
2 2 - None
*/