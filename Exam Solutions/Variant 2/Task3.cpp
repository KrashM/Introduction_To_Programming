#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct Point{
    double x, y;
};

struct Mesh{

    size_t size;
    Point *points;

};

size_t countPositives(Mesh m){

    size_t counter = 0;
    for(size_t i = 0; i < m.size; ++i)
        counter += m.points[i].y >= 0;
    return counter;

}

Mesh positive(Mesh m){

    Mesh posititves;
    posititves.size = countPositives(m);

    posititves.points = new(nothrow) Point[posititves.size];

    if(!posititves.points){

        posititves.size = 0;
        return posititves;

    }

    size_t j = 0;
    for(size_t i = 0; i < m.size; ++i)
        if(m.points[i].y >= 0)
            posititves.points[j++] = m.points[i];
    
    return posititves;

}

int main(){

    Mesh a;

    cin >> a.size;

    a.points = new(nothrow) Point[a.size];
    if(!a.points) return 1;

    for(size_t i = 0; i < a.size; ++i)
        cin >> a.points[i].x >> a.points[i].y;

    Mesh c = positive(a);

    for(size_t i = 0; i < c.size; ++i)
        cout << c.points[i].x << ' ' << c.points[i].y << '\n';

    delete[] a.points;
    delete[] c.points;


}