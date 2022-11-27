#include <iostream>

void generateString(const int n, const int k){

    for(int i = 0; i < k; i++) std::cout << (char)('a' + i);

    int count = 0;
    for(int i = 0; i < n - k; i++){

        std::cout << (char)('a' + count++);
        if(count == k) count = 0;

    }

    std::cout << '\n';

}

int main(){

    int n, k;
    std::cin >> n >> k;
    generateString(n, k);

}