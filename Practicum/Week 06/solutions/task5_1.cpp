#include <iostream>

const unsigned int MAX_SIZE = 100;

void ReadArray(int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void ReverseWithHelperArray(int arr[], const unsigned int n)
{
    int helper[MAX_SIZE];

    for(unsigned i = 0; i < n; i++)
    {
        helper[i] = arr[n - i - 1];
    }

    for(unsigned i = 0; i < n; i++)
    {
        arr[i] = helper[i];
    }
}

void Print(const int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int arr[MAX_SIZE];

    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n == 0 || n > MAX_SIZE);

    ReadArray(arr, n);
    ReverseWithHelperArray(arr, n);
    Print(arr, n);
    
    return 0;
}