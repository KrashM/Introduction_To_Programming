#include <iostream> 

int main() 
{
    int var = 10;
    int* ptr = &var;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;
    std::cout << "Address of ptr: " << &ptr << std::endl;
    std::cout << "Pointer value: " << *ptr << std::endl;

    return 0;
}
