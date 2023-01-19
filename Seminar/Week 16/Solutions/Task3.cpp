#include <iostream>

using std::max;
using std::cin;
using std::cout;
using std::nothrow;

struct coords{
    size_t i, j;
};

void free(long long **&dp, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        delete[] dp[i];
    delete[] dp;

}

bool canGoDiagonal(const coords * const &diagonals, const size_t &size, const size_t &i, const size_t &j){

    for(size_t k = 0; k < size; ++k)
        if(diagonals[k].i == i && diagonals[k].j == j) return true;
    return false;

}

int main(){

    size_t n, k;
    cin >> n;

    long long **dp = new(nothrow) long long*[n];

    if(!dp) return 1;

    for(size_t i = 0; i < n; ++i){

        dp[i] = new(nothrow) long long[n];

        if(!dp[i]){

            free(dp, i);
            return 1;

        }

        for(size_t j = 0; j < n; ++j)
            cin >> dp[i][j];

    }

    cin >> k;

    coords *diagonals = new(nothrow) coords[k];
    
    if(!diagonals) return 1;

    for(size_t i = 0; i < k; ++i)
        cin >> diagonals[i].i >> diagonals[i].j;

    for(size_t i = 1; i < n; ++i) dp[0][i] += dp[0][i - 1];
    for(size_t i = 1; i < n; ++i) dp[i][0] += dp[i - 1][0];

    for(size_t i = 1; i < n; ++i)
        for(size_t j = 1; j < n; ++j)
            if(canGoDiagonal(diagonals, k, i, j)) dp[i][j] += max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            else dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);

    cout << dp[n - 1][n - 1] << '\n';

    delete[] diagonals;

    for(size_t i = 0; i < n; ++i)
        delete[] dp[i];
    delete[] dp;

}