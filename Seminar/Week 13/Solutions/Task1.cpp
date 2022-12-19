#include <iostream>
#include <cmath>

using std::pow;
using std::cin;
using std::cout;
using std::sqrt;

struct point{
    double x, y;
};

double distance(const point &A, const point &B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double halfPerim(const point &A, const point &B, const point &C){
    return (distance(A, B) + distance(A, C) + distance(B, C)) / 2;
}

double area(const point &A, const point &B, const point &C){
    double p = halfPerim(A, B, C);
    return sqrt(p * (p - distance(A, B)) * (p - distance(B, C)) * (p - distance(A, C)));
}

bool checkTriangle(const point &p){

    const point A{-1, 1}, B{1, 1}, C{0, 2};

    if(area(A, B, C) == (area(A, B, p) + area(A, p, C) + area(p, B, C))) cout << "Point is inside\n";
    else return false;
    return true;

}

bool checkRectangle(const point &p) {

    if(p.x > -2 && p.x < 2 && p.y > 2 && p.y < 3) cout << "In Rectangle\n";
    else if (((p.x >= -2 || p.x <= 2) && (p.y == 2 || p.y == 3)) || ((p.x == -2 || p.x == 2) && (p.y >=2 || p.y <= 3))) cout << "Na ruba\n";
    else return false;
    return true;

}

bool checkCircle(const point &p){

    if(p.x * p.x + p.y * p.y < 1) cout << "In Circle\n";
    else if(p.x * p.x + p.y * p.y == 1) cout << "Na ruba\n";
    else return false;
    return true;

}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        
        point point;
        cin >> point.x;
        cin >> point.y;

        if(checkTriangle(point));
        else if(checkRectangle(point));
        else if(checkCircle(point));
        else cout << "Point is outside\n";

    }


}