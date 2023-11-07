#include <iostream>

int pow(int n, int power){

    int result = 1;

    for(int i = 0; i < power; ++i)
        result *= n;

    return result;

}

bool IsArmstrong(int n){

    int counter = 0, sum = 0, copyN = n;

    while(copyN){

        sum += copyN % 10;
        ++counter;
        copyN /= 10;

    }

    return n == pow(sum, counter);

}

int main(){

    for(int i = 1; i <= 1000; ++i)
        if(IsArmstrong(i))
            std::cout << i << ' ';

}