#include <iostream>

int main(){

    int sum = 0, temp;

    do{
        
        std::cin >> temp;
        sum += temp;

    }while(temp != 0);

    std::cout << sum;

}