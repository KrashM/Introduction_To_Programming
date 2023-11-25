#include <iostream>

const int _MAX_SIZE = 100;

void printSubsequences(int array[], int size) {
    int prev = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] <= prev)
            std::cout << '\n';

        std::cout << array[i] << " ";
        prev = array[i];    
    }
    std::cout << std::endl;
}

int main() {
    int array[_MAX_SIZE];
    int size, input;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> input;
        array[i] = input;
    }
    
    printSubsequences(array, size);
   return 0;
}