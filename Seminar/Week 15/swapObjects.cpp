#include <iostream>

using std::cin;
using std::cout;

struct point{
    double x, y;
};

bool compare(const point &a, const point &b){

    if(a.x != b.x) return a.x > b.x;
    return a.y > b.y;

}

void swap(point &a, point &b){

    point temp = a;
    a = b;
    b = temp;

}

void sort(point *points, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(compare(points[i], points[j]))
                swap(points[i], points[j]);

}

int main(){

    size_t n;
    cin >> n;
    point *points = new point[n];

    for(size_t i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    cout << '\n';

    sort(points, n);

    for(size_t i = 0; i < n; ++i)
        cout << points[i].x << ' ' << points[i].y << '\n';

}