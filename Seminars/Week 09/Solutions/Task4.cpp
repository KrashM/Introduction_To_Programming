#include <iostream>

int FindRichestAmount(int const * const * const accounts, size_t const n, size_t const m){

    int richestAmount = INT_MIN, currentAmount;

    for(size_t i = 0; i < n; ++i){

        currentAmount = 0;

        for(size_t j = 0; j < m; ++j)
            currentAmount += accounts[i][j];

        richestAmount = std::max(currentAmount, richestAmount);

    }

    return richestAmount;

}

int main(){

    size_t n, m;
    std::cin >> n >> m;

    int **accounts = new(std::nothrow) int *[n];

    if(!accounts){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i){

        accounts[i] = new(std::nothrow) int[m];
        if(!accounts[i]){

            for(size_t j = 0; j < i; ++j)
                delete[] accounts[j];

            std::cout << "Memory error\n";
            return -1;

        }

        for(size_t j = 0; j < m; ++j) std::cin >> accounts[i][j];

    }


    std::cout << FindRichestAmount(accounts, n, m) << '\n';

    for(size_t i = 0; i < n; ++i) delete[] accounts[i];
    delete[] accounts;

    return 0;

}