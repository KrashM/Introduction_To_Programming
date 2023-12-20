#include <iostream>

const size_t COLS = 10, ROWS = 5;

bool AreLinearlyDependent(double row1[], double row2[])
{
    double k = 0;
    bool calcK = false;
    for (int i = 0; i < COLS; i++){

        if (row1[i] == 0 && row2[i] == 0)
            continue;
        else if (row1[i] * row2[i] == 0)
            return false;
        else
        {
            if (calcK){
                if (k != row1[i] / row2[i])
                    return false;
                else
                    continue;
            }
            else{
                calcK = true;
                k = row1[i] / row2[i];
            }
        }
    }
    return true;
}

bool MatrixHasLDRows(double matrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = i + 1; j < ROWS; j++)
        {
            if (AreLinearlyDependent(matrix[i], matrix[j])){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    double matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << (MatrixHasLDRows(matrix) ? "Yes" : "No") << std::endl;
}
/*
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
2 1 3 4 5 6 8 9 0 10
0 0 0 0 0 0 0 0 0 0
2 1 3 4 1 3 8 7 0 10
Yes

1 2 3 4 5 6 7 8 7 10
1 2 3 4 5 6 7 8 9 10
2 1 3 4 5 6 8 9 0 10
0 0 0 0 0 0 0 0 0 0
2 1 3 4 1 3 8 7 0 10
No

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0.5
0 0 0 0 0 0 0 0 2 1
3 0 0 0 0 0 0 0 0 0
0 4 0 0 0 0 0 0 0 0
Yes

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 2 1
3 0 0 0 0 0 0 0 0 0
0 4 0 0 0 0 0 0 0 0
No

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 2 0
3 0 0 0 0 0 0 0 0 0
0 4 0 0 0 0 0 0 0 0
Yes
*/