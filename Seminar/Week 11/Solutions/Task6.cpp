#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

bool isValidMove(bool **map, const size_t &n, const size_t &x, const size_t &y){

    return x < n && y < n && map[x][y] == 0;

}

bool hasPath(bool **map, const size_t &n, const size_t &sx, const size_t &sy, const size_t &ex, const size_t &ey){

    if(!isValidMove(map, n, sx, sy)) return false;
    if(sx == ex && sy == ey) return true;

    map[sx][sy] = true;

    bool result = hasPath(map, n, sx + 1, sy, ex, ey)
        || hasPath(map, n, sx, sy + 1, ex, ey)
        || hasPath(map, n, sx - 1, sy, ex, ey)
        || hasPath(map, n, sx, sy - 1, ex, ey);
    
    map[sx][sy] = false;

    return result;

}

int main(){

    size_t n;
    cin >> n;

    bool **map = new bool*[n];
    for(size_t i = 0; i < n; ++i){
        
        map[i] = new bool[n];
        for(size_t j = 0; j < n; ++j)
            cin >> map[i][j];

    }

    size_t sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    cout << std::boolalpha << hasPath(map, n, sx, sy, ex, ey) << '\n';

    for(size_t i = 0; i < n; ++i) delete[] map[i];
    delete[] map;

}