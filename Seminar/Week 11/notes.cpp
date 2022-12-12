#include <iostream>

using std::cin;
using std::cout;

// binary search реализиран с рекурсия
bool binarySearch(int *arr, int start, int end, int x){

    int mid = (start + end) / 2;

    if(arr[mid] == x) return true;
    if(start >= end) return false;

    if(arr[mid] > x) return binarySearch(arr, start, mid - 1, x);
    return binarySearch(arr, mid + 1, end, x);

}

// Функция намираща n^k
unsigned int pow(unsigned int n, unsigned int k){

    if(k == 0) return 1;
    return n * pow(n, k - 1);

}

// Проста рекурсивна функция репрезентираща цикъл
void iterator(unsigned int i, unsigned int n){

    if(i >= n) return;
    cout << i << '\n';
    iterator(i + 1, n);

}

// Функция за намиране на n-тия елемент на фибуначи(n)
unsigned int fibFaster(unsigned int n, unsigned int prevPrev, unsigned int prev, unsigned int index){

    if(index == n) return prev;
    return fibFaster(n, prev, prevPrev + prev, index + 1);

}

// Функция намираща n-тия елемент на фибуначи(2^n)
unsigned int fib(unsigned int n){

    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);

}

// Функция за факториел
unsigned int factoriel(unsigned int n){

    if(n == 0 || n == 1) return 1;
    return n * factoriel(n - 1);

}

// Функция за сумиране на първите n естествени числа
unsigned int sumNIntegers(unsigned int n){

    if(n == 0) return 0;
    return n + sumNIntegers(n - 1);

}

// Пример за рекурсия и backtracking
void print(unsigned int n){


    if(n == 0) return;
    cout << n << '\n'; // Изпълнение при влизане 5 4 3 2 1
    print(n - 1);
    cout << n << '\n'; // Изпълнение при излизане 1 2 3 4 5

}

// Задача 1 от домашното
char findFirstUppercase(char *str){

    if(*str == '\0') return '\0';
    if(*str >= 'A' && *str <= 'Z') return *str;
    return findFirstUppercase(str + 1);

}

int main(){

    // int arr[] = { 1, 2 ,3 ,4, 5, 5, 7,8, 9, 10};
    // cout << std::boolalpha << binarySearch(arr, 0, 10, 6) << '\n';

    // unsigned int n, i;
    // cin >> n >> i;
    // iterator(i, n);
    // cout << pow(10, 4);
    // cout << fibFaster(n, 0, 1, 1) << '\n';
    // cout << fib(n) << '\n';
    // cout << sumNIntegers(n) << '\n';
    // print(5);

    char str[255];
    cin.getline(str, 255);

    cout << findFirstUppercase(str) << '\n';

}