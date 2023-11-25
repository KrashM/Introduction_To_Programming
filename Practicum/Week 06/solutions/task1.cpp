#include <iostream>

void ReadArray(int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void PrintReverse(const int arr[], const unsigned int n)
{
    for(int i = n - 1; i >= 0; i--)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    const unsigned int MAX_SIZE = 100;
    int arr[MAX_SIZE];

    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n == 0 || n > MAX_SIZE);
    
    ReadArray(arr, n);
    PrintReverse(arr, n);
    return 0;
}