#include <iostream>

int Multiples(int a, int b, int x){

    int count = 0;

    for(int i = a; i <= b; ++i){

        if(!i) continue;
        count += !(i % x);

    }

    return count;

}

int main(){

    int a, b, x;
    std::cin >> a >> b >> x;
    std::cout << Multiples(a, b, x) << '\n';

    return 0;

}