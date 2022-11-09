#include <iostream>
#include <cmath>

bool is2Divisible(int x){

    for(int i = 0; i < std::sqrt(x); i++)
        if(i * (i + 1) == x) return true;

    return false;

}

int main(){

    int a, b, count = 0;
    std::cin >> a >> b;

    for(int i = a; i <= b; i++) count += is2Divisible(i);

    std::cout << count << '\n';
    
}