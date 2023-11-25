#include <iostream>

void ReadArray(int arr[], const unsigned int n)
{
    std::cout << "Enter array: ";
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void InsertIntoSortedArray(int sortedArr[], unsigned int& n, const int num)
{
    bool inserted = false;

    for(unsigned i = 0; i < n && !inserted; i++)
    {
        if(sortedArr[i] > num)
        {
            for(int j = n; j > i; j--)
            {
                sortedArr[j] = sortedArr[j - 1];
            }

            sortedArr[i] = num;
            n++;
            inserted = true;
        }
    }

    if(!inserted)
    {
        sortedArr[n] = num;
        n++;
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
    int sortedArr[MAX_SIZE];

    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n == 0 || n > MAX_SIZE);

    ReadArray(sortedArr, n);

    unsigned int k;
    do
    {
        std::cout << "\nEnter k: ";
        std::cin >> k;
    } while(k == 0 || k + n > MAX_SIZE);

    std::cout << "Enter k numbers: ";
    for(unsigned i = 0; i < k; i++)
    {
        int num;
        std::cin >> num;

        InsertIntoSortedArray(sortedArr, n, num);
    }

    std::cout << std::endl;
    Print(sortedArr, n);
    return 0;
}