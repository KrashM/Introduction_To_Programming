#include <iostream>
#include <cmath> // Библиотека за математически функции(abs, sqr, sqrt...)
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    cout << n + m << endl;
    cout << abs(n - m) << endl;
    cout << n % m << endl;
    cout << n / m << endl;
    cout << n * 1.0 / m << endl;
    cout << floor(n * 1.0 / m) << endl;
    cout << ceil(n * 1.0 / m) << endl;
    cout << pow(n,2) + sqrt(m) << endl;

}