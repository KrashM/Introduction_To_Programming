#include <iostream>

void ReadArray(unsigned int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void Modify(unsigned int arr[], const unsigned int n)
{
    for(unsigned i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }
}

void PrintArray(const unsigned int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    const unsigned int MAX_SIZE = 100;
    unsigned int arr[MAX_SIZE];

    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n == 0 || n > MAX_SIZE);
    
    ReadArray(arr, n);
    Modify(arr, n);
    PrintArray(arr, n);
    
    return 0;
}
