#include <iostream>

using std::min;
using std::cin;
using std::cout;
using std::swap;
using std::size_t;


int gcd(const int &a, const int &b){

    if(b == 0) return a;
    return gcd(b, a % b);

}

int lcm(const int &a, const int &b){

    return (a / gcd(a, b)) * b;

}

bool rowIsNotZeroes(int **mat, const size_t &row, const size_t &m){

    for(size_t j = 0; j < m; j++)
        if(mat[row][j]) return true;
    return false;

}

size_t findRank(int **mat, const size_t &n, const size_t &m){

    int rank = n, leastCommonMultiple, multiplyerFirstRow, multiplyerSecondRow;
    bool hasNumberInColumn, reduce;

    for(size_t row = 0; row < rank; row++){

        if(mat[row][row])
            for(size_t col = 0; col < n; col++){

                if(col != row && mat[col][row] != 0){

                    leastCommonMultiple = lcm(mat[row][row], mat[col][row]);
                    multiplyerFirstRow =  leastCommonMultiple / mat[row][row];
                    multiplyerSecondRow =  leastCommonMultiple / mat[col][row];

                    for(size_t i = 0; i < m; i++)
                        mat[col][i] = mat[col][i] * multiplyerSecondRow - mat[row][i] * multiplyerFirstRow;

                }

            }
        else{
            
            hasNumberInColumn = false;
            for(size_t i = row + 1; i < rank;  i++){

                if(mat[i][row]){

                    
                    for(size_t j = 0; j < rank; ++j)
                        swap(mat[row][j], mat[i][j]);
                    hasNumberInColumn = true;
                    break;

                }

            }

            if(!hasNumberInColumn){

                reduce = true;

                for(size_t i = 0; i < m; i++)
                    if(mat[row][i]) reduce = false;

                if(reduce){


                    for(size_t j = 0; j < rank; ++j)
                        swap(mat[row][j], mat[rank - 1][j]);
                    rank--;

                }

            }

            if(!rowIsNotZeroes(mat, row, m)) row--;

        }

    }

    return rank;

}

int main(){

    size_t n, m;
    cin >> n >> m;

    int **matrix = new int *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new int[m];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            cin >> matrix[i][j];

    cout << findRank(matrix, n, m) << '\n';

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}