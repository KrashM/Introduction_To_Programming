#include <iostream>

const size_t MAX_SIZE = 100;

bool CanFormRigthTriangle(double a, double b, double c)
{
    if (a == 0 || b == 0 || c == 0)
        return false;
    if (a * a + b * b == c * c)
        return true;
    if (c * c + b * b == a * a)
        return true;
    if (a * a + c * c == b * b)
        return true;
    return false;
}

bool HasTriangles(double arr1[], double arr2[], double arr3[], size_t n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (CanFormRigthTriangle(arr1[i], arr2[j], arr3[k]))
                    return true;
            }
        }
    }
    return false;
}

void InputArr(double *arr, size_t n)
{
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

int main()
{
    size_t n;
    double arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE];
    std::cin >> n;
    InputArr(arr1, n);
    InputArr(arr2, n);
    InputArr(arr3, n);
    std::cout << "Can " << (HasTriangles(arr1, arr2, arr3, n) ? "" : "not ") << "form a rigth triangle" << std::endl;
}
/*
3
1 3 5
1 2 4
0 3 6

Can form a rigth triangle
----------------------------
3
1 3 5
1 2 4
1 4 6

Can not form a rigth triangle

*/