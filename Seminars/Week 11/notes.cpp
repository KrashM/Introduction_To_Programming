#include <iostream>

// Пример за рекурсия и backtracking
void print(unsigned int n){


    std::cout << n << '\n'; // n, (n-1), ..., 1, 0
    if(n == 0) return;
    print(n - 1);

}

// Проста рекурсивна функция репрезентираща цикъл
void iterator(unsigned int i, unsigned int n){

    if(i >= n) return;
    std::cout << i << '\n';
    iterator(i + 1, n);

}

// Функция за сумиране на първите n естествени числа
unsigned int sumNIntegers(unsigned int n){

    if(n == 0) return 0;
    return n + sumNIntegers(n - 1);

}

// Функция за факториел
unsigned int factoriel(unsigned int n){

    if(n == 0 || n == 1) return 1;
    return n * factoriel(n - 1);

}

// Задача 1 от домашното
char findFirstUppercase(char *str){

    if(*str == '\0') return '\0';
    if(*str >= 'A' && *str <= 'Z') return *str;
    return findFirstUppercase(str + 1);

}

// Функция намираща n^k
unsigned int pow(unsigned int n, unsigned int k){

    if(k == 0) return 1;
    return n * pow(n, k - 1);

}

// Функция намираща n-тия елемент на фибуначи O(2^n)
unsigned int fib(unsigned int n){

    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);

}

// Функция за намиране на n-тия елемент на фибуначи O(n)
unsigned int fibFaster(unsigned int n, unsigned int prevPrev, unsigned int prev, unsigned int index){

    if(index == n) return prev;
    return fibFaster(n, prev, prevPrev + prev, index + 1);

}

// binary search реализиран с рекурсия O(logn)
bool binarySearch(int *arr, int start, int end, int x){

    int mid = (start + end) / 2;

    if(arr[mid] == x) return true;
    if(start >= end) return false;

    if(arr[mid] > x) return binarySearch(arr, start, mid - 1, x);
    return binarySearch(arr, mid + 1, end, x);

}

int main(){

    int arr[] = { 1, 2 ,3 ,4, 5, 5, 7,8, 9, 10};
    std::cout << std::boolalpha << binarySearch(arr, 0, 10, 6) << '\n';

    unsigned int n, i;
    std::cin >> n >> i;
    iterator(i, n);
    std::cout << pow(10, 4);
    std::cout << fibFaster(n, 0, 1, 1) << '\n';
    std::cout << fib(n) << '\n';
    std::cout << sumNIntegers(n) << '\n';
    print(5);

    char str[255];
    std::cin.getline(str, 255);

    std::cout << findFirstUppercase(str) << '\n';

}