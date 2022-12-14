#include <iostream>

using std::cin;
using std::cout;

struct Point{

    int x, y;
    double distanceFromOrigin;
    char *name;

};

int main(){

    Point A{3, 1, 5.14};

    char str[] = "Hello World";
    A.name = str;

    cout << A.x << ' ' << A.y << ' ' << A.name << ' ' << A.distanceFromOrigin;

}