#include <iostream>

using std::cin;
using std::cout;

struct point{

    int x, y;

};

bool pointsAreEqual(point a, point b){
    return ((a.x == b.x) && (a.y == b.y));
}

bool isInside(point location, int n){
    return location.x > 0 && location.x < n && location.y > 0 && location.y < n;
}

bool findRoute(int **map, int n, point location, point startLocation, point grannyPoint, int load, int capacity, bool **used, bool returning, point *path, int &index){

    if(!isInside(location, n)) return false;

    if(pointsAreEqual(location, grannyPoint)) returning = true;
    if(returning && pointsAreEqual(location, startLocation)) return true;

    load += map[location.y][location.x];
    if(load > capacity || load < 0) return false;

    if(used[location.y][location.x]) return false;
    used[location.y][location.x] = true;

    path[index] = location;
    index++;

    point up = location, right = location, down = location, left = location;
    down.y++;
    right.x++;
    up.y--;
    left.x--;

    bool result = findRoute(map, n, down, startLocation, grannyPoint, load, capacity, used, returning, path, index) ||
                findRoute(map, n, right, startLocation, grannyPoint, load, capacity, used, returning, path, index) ||
                findRoute(map, n, up, startLocation, grannyPoint, load, capacity, used, returning, path, index) ||
                findRoute(map, n, left, startLocation, grannyPoint, load, capacity, used, returning, path, index);

    used[location.y][location.x] = false;
    if(!result) index--;
    
    return result;

}

int main(){

    int n;
    cin >> n;

    int **map = new int*[n];
    for(int i = 0; i < n; i++){

        map[i] = new int[n];
        for(int j = 0; j < n; j++)
            cin >> map[i][j];

    }
    
    point startPoint, grannyPoint;
    cin >> startPoint.y >> startPoint.x >> grannyPoint.y >> grannyPoint.x;

    int capacity;
    cin >> capacity;

    bool **used = new bool*[n];
    for(int i = 0; i < n; i++){

        used[i] = new bool[n];
        for(int j = 0; j < n; j++)
            used[i][j] = false;

    }

    point *path = new point[n * n];
    int index = 0;

    cout << ((findRoute(map, n, startPoint, startPoint, grannyPoint, 0, capacity, used, false, path, index)) ? "true\n" : "false\n");

    for(int i = 0; i < index; i++)
        cout << '(' << path[i].y << ',' << path[i].x << ")\n";
    cout << '(' << startPoint.y << ',' << startPoint.x << ")\n";

    for(int i = 0; i < n; i++) delete[] map[i];
    delete[] map;

    for(int i = 0; i < n; i++) delete[] used[i];
    delete[] used;

    delete[] path;
    
}

/*

5
1 5 6 4 -2
-4 10 4 -3 20
0 -4 2 -12 5
5 13 1 1 -7
2 7 5 0 15
1 1
4 3
15

*/