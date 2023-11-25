#include <iostream>

void ReadArray(int arr[], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ReverseWithoutHelperArray(int arr[], const unsigned int n)
{
    int middle = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    for(int i = 0; i < middle; i++)
    {
        Swap(arr[i], arr[n - i - 1]);
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
    const unsigned int MAX_SIZE = 100;
    int arr[MAX_SIZE];

    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n == 0 || n > MAX_SIZE);

    ReadArray(arr, n);
    ReverseWithoutHelperArray(arr, n);
    Print(arr, n);
    
    return 0;
}