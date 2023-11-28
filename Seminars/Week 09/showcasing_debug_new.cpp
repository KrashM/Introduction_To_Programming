#include <iostream>
#include "debug_new.h"

// Not using std::nothrow, because it breaks the program.
// My code will not throw an error anyways.

int main(){

    int a = 10;
    int *ptr = &a;

    printList();

    std::cout << ptr << ' ' << *ptr << '\n';

    ptr = new(std::nothrow) int(5);

    std::cout << ptr << ' ' << *ptr << '\n';


    std::cout << "Print 1:\n";
    printList();

    delete ptr;

    std::cout << "Print 2:\n";
    printList();

    int **matrix = new(std::nothrow) int*[10];

    for(size_t i = 0; i < 10; ++i)
        matrix[i] = new(std::nothrow) int[7];

    std::cout << "Print 3:\n";
    printList();

    for(size_t i = 0; i < 10; ++i)
        delete[] matrix[i];

    std::cout << "Print 4:\n";
    printList();

    delete[] matrix;

    std::cout << "Print 5:\n";
    checkMemoryLeaks();

}