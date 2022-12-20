#include <iostream>

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::size_t;

struct point{
    double x, y;
};

int main(){

    double minX, maxX, minY, maxY, maxLen;
    point temp;
    size_t n;

    cin >> n;

    cin >> temp.x >> temp.y;

    minX = maxX = temp.x;
    minY = maxY = temp.y;

    for(size_t i = 1; i < n; ++i){

        cin >> temp.x >> temp.y;

        minX = min(minX, temp.x);
        minY = min(minY, temp.y);
        maxX = max(maxX, temp.x);
        maxY = max(maxY, temp.y);

    }

    maxLen = max(maxX - minX, maxY - minY);
    cout << maxLen * maxLen << '\n';
    
}