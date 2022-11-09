#include <iostream>

int main(){

    char str[] = "Hello";
    std::cout << "String legth is: " << sizeof(str) << '\n';
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::cout << "Array size is: " << sizeof(arr) << " Array length is: " << sizeof(arr) / sizeof(arr[0]) << '\n';

}