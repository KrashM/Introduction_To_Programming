#include <iostream>
const unsigned int CAPACITY = 100;
void reduceRow (unsigned int &n, unsigned int &m, int arr[][3], unsigned int k) {

    for (size_t i = k; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[i][j] = arr[i + 1][j];
        }
    }
    n--;
}

void reduceCol (unsigned int &n, unsigned int &m, int arr[][3], unsigned int p) {

    //reducing
    for (size_t i = p; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[j][i] = arr[j][i + 1];
        }
    }
    m--;
}

void reduce(){}

int main() {
    unsigned int n = 3,m = 3, p = 1, k = 2;
    int arr[3][3] = { {1, 2, 3}, 
                    {4, 5, 6},
                    {7, 8, 9}};

    reduceRow(n, m, arr, p);
    reduceCol(n, m, arr, k );

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}