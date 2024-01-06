#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 100;
const size_t MAX_LEN = 11;

void Read(char matrix[][MAX_SIZE][MAX_LEN], const size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

bool IsSymetrical(const char matrix[][MAX_SIZE][MAX_LEN], const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(strcmp(matrix[i][j], matrix[j][i]))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char matrix[MAX_SIZE][MAX_SIZE][MAX_LEN];
    size_t n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while (n > MAX_SIZE);
    
    Read(matrix, n);
    std::cout << std::boolalpha << IsSymetrical(matrix, n) << std::endl;
    return 0;
}