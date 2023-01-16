#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;
using std::boolalpha;

struct point{
    size_t x, y;
};

const size_t SIZE = 8;

bool isValidMove(const bool maze[][SIZE], const point &current){
    return !maze[current.x][current.y] && current.x < SIZE && current.y < SIZE;
}

bool path(bool maze[][8], const point &current, const point &to){

    if(!isValidMove(maze, current)) return false;
    if(current.x == to.x && current.y == to.y) return true;

    maze[current.x][current.y] = true;

    return path(maze, {current.x, current.y + 1}, to) ||
        path(maze, {current.x + 1, current.y}, to) ||
        path(maze, {current.x - 1, current.y}, to) ||
        path(maze, {current.x, current.y - 1}, to);

}

// Бонус
bool path(bool maze[][SIZE], const point &current, const point &to, point *steps, size_t &pathSize){

    if(!isValidMove(maze, current)) return false;

    steps[pathSize++] = current;
    
    if(current.x == to.x && current.y == to.y) return true;

    maze[current.x][current.y] = true;

    bool result = path(maze, {current.x, current.y - 1}, to, steps, pathSize) ||
        path(maze, {current.x - 1, current.y}, to, steps, pathSize) ||
        path(maze, {current.x, current.y + 1}, to, steps, pathSize) ||
        path(maze, {current.x + 1, current.y}, to, steps, pathSize);
    
    if(!result) --pathSize;

    return result;

}

void printPath(const point * const &steps, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        if(i != 0) cout << " -> (" << steps[i].x << ", " << steps[i].y << ')';
        else cout << '(' << steps[i].x << ", " << steps[i].y << ')';
    cout << '\n';

}

void logic(){

    bool maze[SIZE][SIZE] = {
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 0}
    };

    point from, to;
    cin >> from.x >> from.y >> to.x >> to.y;

    cout << boolalpha << path(maze, from, to) << '\n';

    // Бонус
    point steps[SIZE * SIZE];
    size_t pathSize = 0;

    bool newMaze[SIZE][SIZE] = {
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 0}
    };

    cout << boolalpha << path(newMaze, from, to, steps, pathSize) << '\n';
    printPath(steps, pathSize);

}

int main(){
    logic();
}