#include <iostream>

int horner(const int poly[], const int n, const int x){

    int result = poly[0];
    for(int i = 1; i < n; i++) result = result*x + poly[i];
    return result;

}

int main(){

    int poly[] = {2, -6, 2, -1}, x = 3, n = sizeof(poly)/sizeof(poly[0]);
    std::cout << "Value of polynomial is " << horner(poly, n, x) << '\n';

}