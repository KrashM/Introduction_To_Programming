#include<iostream>

void sort(int array[], int n);

int main(){

    int array[] = {3, 45, 1535, 7, 67, 4, 1};
    
    for(unsigned i = 0; i < sizeof(array) / 4; i++) std :: cout << array[i] << ' ';
    std :: cout << '\n';

    sort(array, sizeof(array) / 4);

    for(unsigned i = 0; i < sizeof(array) / 4; i++) std :: cout << array[i] << ' ';
    std :: cout << '\n';

    return 0;

}

void Heapify(int array[], int n, int i){

    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && array[l] > array[largest]) largest = l;

    if (r < n && array[r] > array[largest]) largest = r;

    if (largest != i){

        std :: swap(array[i], array[largest]);
        Heapify(array, n, largest);

    }

}

void sort(int array[], int n){
    
    for (int i = n / 2 - 1; i >= 0; i--) Heapify(array, n, i);

    for (int i=n-1; i>=0; i--){
        
        std :: swap(array[0], array[i]);
        Heapify(array, i, 0);

    }
    
}