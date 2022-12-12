#include <iostream>

using std::cin;
using std::cout;

void printPiramid(const unsigned int &n, const unsigned int &i, unsigned int row){

    if(i == n * (n + 1) / 2) return;
    if(i == row * (row + 1) / 2){

        ++row;
        cout << '\n';

    }
    cout << i + 1 << ' ';
    printPiramid(n, i + 1, row);

}

int main(){

    unsigned int n;
    cin >> n;

    printPiramid(n, 0, 1);

}