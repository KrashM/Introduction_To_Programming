#include <iostream>

int main(){

    int n;
    bool flag = true;
    std::cin >> n;

    while(n != 1){

        if(n % 2){

            flag = false;
            break;

        }

        n /= 2;

    }

    std::cout << std::boolalpha << flag << '\n';

}