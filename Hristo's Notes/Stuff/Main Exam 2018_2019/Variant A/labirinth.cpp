#include<iostream>

bool reachable(int A[][100], unsigned N, int sx, int sy, int target);

int main(){

    int array[][100] = {
        {1, 10, 0, 0},
        {4, 10, 0, 0},
        {2, 0, 3, 3},
        {4, 10, 6, 5}
    };

    int sx = 0, sy = 0;
    unsigned N = 4;
    int target = 5;

    std :: cout << reachable(array, N, sx, sy, target) << '\n';

    return 0;

}

bool reachable(int A[][100], unsigned N, int sx, int sy, int target){

    if(sx >= N || sy >= N) return false;
    if(A[sy][sx] > target) return false;
    
    if(A[sy][sx] == target) return true;

    return reachable(A, N, sx + 1, sy + 1, target) || reachable(A, N, sx + 1, sy, target) || reachable(A, N, sx, sy + 1, target);

}