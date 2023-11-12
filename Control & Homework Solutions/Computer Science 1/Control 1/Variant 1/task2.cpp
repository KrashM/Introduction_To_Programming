#include <iostream>

void Divisors(int a, int b, int x){

    for(int i = a; i <= b; ++i){

        if(!i) continue;
        if(!(x % i)) std::cout << i << ' ';

    }

}

int main(){

    int a, b, x;
    std::cin >> a >> b >> x;
    Divisors(a, b, x);

    return 0;

}