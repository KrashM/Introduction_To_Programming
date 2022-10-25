#include <iostream>

int main(){

    unsigned int n, result = 1;
    std::cin >> n;

    while(n > 0){

        result *= n;
        n--;

    }

    // Вариант с for цикъл
    // for(unsigned int i = 1; i <= n; i++){

    //     result *= i;

    // }

    std::cout << result << '\n';

}