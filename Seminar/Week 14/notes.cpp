#include <iostream>

using std::cin;
using std::cout;

int max(const int &a, const int &b){
    return a > b ? a : b;
}

int getMax(const int *arr, const size_t &n){

    if(n == 0) return INT_MIN;
    return max(*arr, getMax(arr + 1, n - 1));

}

int sumAll(const int *arr, const size_t &n){

    if(n == 0) return 0;
    return *arr + sumAll(arr + 1, n - 1);

}

void printSet(const int *arr, const bool *bitString, const size_t &n){

    cout << "{ ";

    for(size_t i = 0; i < n; ++i){

        if(bitString[i])
            cout << arr[i] << " ";

    }

    cout << "}\n";

}

void generateSubsets(const int *arr, const size_t &current, const size_t &n, bool *bitString){

    if(current == n){

        printSet(arr, bitString, n);
        return;

    }

    bitString[current] = 0;
    generateSubsets(arr, current + 1, n, bitString);

    bitString[current] = 1;
    generateSubsets(arr, current + 1, n, bitString);

}

void printAllSubSets(const int *arr, const size_t &n){

    bool *bitString = new bool[n];
    generateSubsets(arr, 0, n, bitString);
    delete[] bitString;

}

int main(){

    const size_t SIZE = 1024;
    int arr[SIZE];

    size_t n;
    cin >> n;

    for(size_t i = 0; i < n; ++i) cin >> arr[i];

    cout << getMax(arr, n) << '\n';
    cout << sumAll(arr, n) << '\n';
    printAllSubSets(arr, n);
    
}