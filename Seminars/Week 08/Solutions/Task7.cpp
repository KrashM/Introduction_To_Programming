#include <iostream>

size_t const CAPACITY = 100;

int GCD(int const a, int const b){
    
    int result = std::min(a, b);

    if(a % result == 0 && b % result == 0) return result;

    for(int i = result / 2; i >= 2; --i)
        if(a % result == 0 && b % result == 0) return result;
    
    return 1;

}

int LCM(int const a, int const b){
    return (a / GCD(a, b)) * b;
}

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

bool RowIsNotZeroes(int const mat[][CAPACITY], size_t const row, size_t const m){

    for(size_t j = 0; j < m; j++)
        if(mat[row][j]) return true;
    return false;

}

size_t FindRank(int mat[][CAPACITY], size_t const n, size_t const m){

    int rank = n, leastCommonMultiple, multiplyerFirstRow, multiplyerSecondRow;
    bool hasNumberInColumn, reduce;

    for(size_t row = 0; row < rank; row++){

        if(mat[row][row])
            for(size_t col = 0; col < n; col++){

                if(col != row && mat[col][row] != 0){

                    leastCommonMultiple = LCM(mat[row][row], mat[col][row]);
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
                        Swap(mat[row][j], mat[i][j]);
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
                        Swap(mat[row][j], mat[rank - 1][j]);
                    rank--;

                }

            }

            if(!RowIsNotZeroes(mat, row, m)) row--;

        }

    }

    return rank;

}

int main(){

    int matrix[CAPACITY][CAPACITY];
    size_t n, m;
    std::cin >> n >> m;

    if(n >= CAPACITY || m >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            std::cin >> matrix[i][j];

    std::cout << FindRank(matrix, n, m) << '\n';

    return 0;

}