#include <iostream>
#include <cstddef>
#include <new>

bool IsValidMove(bool **map, size_t const n, size_t const x, size_t const y){
    return x < n && y < n && map[x][y] == 0;
}

bool HasPath(bool **map, size_t const n, size_t const sx, size_t const sy, size_t const ex, size_t const ey){

    if(!IsValidMove(map, n, sx, sy)) return false;
    if(sx == ex && sy == ey) return true;

    map[sx][sy] = true;

    bool result = HasPath(map, n, sx + 1, sy, ex, ey)
        || HasPath(map, n, sx, sy + 1, ex, ey)
        || HasPath(map, n, sx - 1, sy, ex, ey)
        || HasPath(map, n, sx, sy - 1, ex, ey);
    
    map[sx][sy] = false;

    return result;

}

void FreeMatrix(bool const * const * const map, size_t const rows){

    for(size_t i = 0; i < rows; ++i)
        delete[] map[i];
    delete[] map;

}

int main(){

    size_t n;
    std::cin >> n;

    bool **map = new(std::nothrow) bool*[n];

    if(!map){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i){
        
        map[i] = new(std::nothrow) bool[n];

        if(!map[i]){

            std::cout << "Memory error\n";
            FreeMatrix(map, i);
            return -1;

        }

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            std::cin >> map[i][j];

    size_t sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;

    std::cout << std::boolalpha << HasPath(map, n, sx, sy, ex, ey) << '\n';

    FreeMatrix(map, n);

    return 0;

}