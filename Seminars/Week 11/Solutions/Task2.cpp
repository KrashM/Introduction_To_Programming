#include <iostream>

void PrintPiramid(unsigned const n, unsigned const i, unsigned row){

    if(i == n * (n + 1) / 2) return;
    if(i == row * (row + 1) / 2){

        ++row;
        std::cout << '\n';

    }
    std::cout << i + 1 << ' ';
    PrintPiramid(n, i + 1, row);

}

int main(){

    unsigned int n;
    std::cin >> n;

    PrintPiramid(n, 0, 1);

    return 0;

}