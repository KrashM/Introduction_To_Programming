#include <iostream>

const unsigned int MAX_SIZE = 100;

unsigned int ReadSize()
{
    unsigned int size;
    do
    {
        std::cin >> size;
    } while (size == 0 || size > MAX_SIZE);

    return size;
}

void ReadMatrix(int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void fillWithFalse(bool arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

bool isValidSudoku(int matrix[][MAX_SIZE])
{
    bool usedNumbers[10];

    // Check rows
    for (unsigned i = 0; i < 9; i++)
    {
        fillWithFalse(usedNumbers, 10);
        for (unsigned j = 0; j < 9; j++)
        {
            if (usedNumbers[matrix[i][j]])
                return false;
            usedNumbers[matrix[i][j]] = true;
        }
    }

    // Check columns
    for (unsigned i = 0; i < 9; i++)
    {
        fillWithFalse(usedNumbers, 10);
        for (unsigned j = 0; j < 9; j++)
        {
            if (usedNumbers[matrix[j][i]])
                return false;
            usedNumbers[matrix[j][i]] = true;
        }
    }

    // Check small squares
    for (unsigned x = 0; x < 3; x++)
    {
        for (unsigned y = 0; y < 3; y++)
        {
            fillWithFalse(usedNumbers, 10);
            for (unsigned i = 0; i < 3; i++)
            {
                for (unsigned j = 0; j < 3; j++)
                {
                    if (usedNumbers[matrix[j][i]])
                        return false;
                    usedNumbers[matrix[j][i]] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    ReadMatrix(matrix, 9, 9);

    std::cout << std::endl
              << isValidSudoku(matrix);
    return 0;
}