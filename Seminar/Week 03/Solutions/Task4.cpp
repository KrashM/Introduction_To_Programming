#include <iostream>

int main(){

    int n, answer = 0;
    bool negative = n < 0;
    std::cin >> n;

    while(n != 0){

        answer *= 10;
        answer += n % 10;
        n /= 10;

    }

    if(negative){
        
        answer *= -1;

    }

    std::cout << answer << '\n';

}