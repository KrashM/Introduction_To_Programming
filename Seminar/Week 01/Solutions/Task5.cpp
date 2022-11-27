#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int flipped = 100 * (n % 10) + 10 * ((n / 10) % 10) + n / 100;
    cout << flipped;

}