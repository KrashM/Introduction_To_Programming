#include <iostream>

void modify(int arr[], const unsigned int size){

    if(size <= 1) return;

    int prev = arr[0], curr;
    arr[0] = arr[0] * arr[1];
    
    for(int i = 1; i < size - 1; i++){
    
        curr = arr[i];
        arr[i] = prev * arr[i + 1];
        prev = curr;
    
    }

    arr[size - 1] = prev * arr[size - 1];

}
 
int main(){
    
    int arr[] = { 2, 3, 4, 5, 6 };
    const unsigned int size = sizeof(arr) / sizeof(arr[0]);
    modify(arr, size);
    for(int i = 0; i < size; i++) std::cout << arr[i] << " ";

}