#include<iostream>

bool reachable(int A[][100], unsigned N, int sx, int sy, int target);
bool reachable(int A[][100], unsigned N, int sx, int sy, int target, int last);

int main(){

    int array[][100] = {
        {1, 0, 1, 1},
        {10, 15, 1, 1},
        {50, 20, 50, 50},
        {40, 0, 40, 60}
    };

    int sx = 0, sy = 0;
    unsigned N = 4;
    int target = 60;

    std :: cout << reachable(array, N, sx, sy, target) << '\n';

    return 0;

}

bool reachable(int A[][100], unsigned N, int sx, int sy, int target){
    return reachable(A, N, sx, sy, target, A[sx + 1][sy + 1]) || reachable(A, N, sx, sy, target, A[sx + 1][sy]) || reachable(A, N, sx, sy, target, A[sx][sy + 1]);
}

bool reachable(int A[][100], unsigned N, int sx, int sy, int target, int last){

    if(sx >= N || sy >= N) return false;
    if(A[sy][sx] > target) return false;
    if(A[sx][sy] <= last) return false;
    
    if(A[sy][sx] == target) return true;

    return reachable(A, N, sx + 1, sy + 1, target, A[sx][sy]) || reachable(A, N, sx + 1, sy, target, A[sx][sy]) || reachable(A, N, sx, sy + 1, target, A[sx][sy]);

}