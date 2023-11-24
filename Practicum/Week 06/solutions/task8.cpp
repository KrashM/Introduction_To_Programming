#include <iostream>

const int MAX_SIZE = 100;

void printPairs(int arr[], int size, int m) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == m)
                std::cout << arr[i] << " " << arr[j] << std::endl;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size, m;
    std::cin >> size >> m;

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    printPairs(arr, size, m);
    
   return 0;
}