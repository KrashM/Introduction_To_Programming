#include <iostream>

int main(){

    unsigned int n;
    std::cin >> n;

    for (unsigned int i = 1; i <= n; i++){

        for (unsigned int j = 0; j < n - i; j++){
            std::cout << " ";
        }

        for (unsigned int j = 0; j < i; j++){
            std::cout << "* ";
        }
        
        std::cout << '\n';

    }
    
}