#include <iostream>


const unsigned int MAX_SIZE = 100;

unsigned int ReadIndex(unsigned int max){
    unsigned int index;
    do
    {
        std::cin >> index;
    } while(index >= max);

    return index;

}

unsigned int ReadSize()
{
    unsigned int size;
    do
    {
        std::cin >> size;
    } while(size == 0 || size > MAX_SIZE);

    return size;
}

void ReadMatrix(int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }    
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}


void RemoveRow(int matrix[][MAX_SIZE], unsigned int &n, unsigned int &m, const unsigned int row)
{
    for(unsigned i = row; i < n - 1; i++){
        for(unsigned j = 0; j < m; j++){
            swap(matrix[i][j],matrix[i+1][j]);
        }
    }
    for(unsigned j = 0; j < m; j++)
        matrix[n-1][j]=0;    
    n--;
}

void RemoveColumn(int matrix[][MAX_SIZE], unsigned int &n, unsigned int &m, const unsigned int col)
{
    for(unsigned i = 0; i < n ; i++){
        for(unsigned j = col; j < m - 1; j++){
            swap(matrix[i][j],matrix[i][j+1]);
        }
    }
    for(unsigned i = 0; i < n; i++)
        matrix[i][m-1]=0;    
    m--;
}

void PrintMatrix(const int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }  
}


int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    unsigned int n = ReadSize(),
                 m = ReadSize();

    ReadMatrix(matrix, n, m);
    
    unsigned int row = ReadIndex(n),
                 col = ReadIndex(m);
    
    RemoveRow(matrix, n, m, row);
    RemoveColumn(matrix, n, m, col);
    
    std::cout << std::endl;
    PrintMatrix(matrix, n, m);
    
    return 0;
}