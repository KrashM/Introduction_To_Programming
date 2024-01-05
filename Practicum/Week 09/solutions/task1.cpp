#include <iostream> 

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int a = 3, b = 5;
    Swap(&a, &b);
    std::cout << "a = " << a << ", "
              << "b = " << b << std::endl;
    return 0;
}
