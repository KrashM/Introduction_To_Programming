#include <iostream>

void removeDuplicates(int arr[], unsigned int &size){

    for(unsigned int i = 0; i < size - 1; i++){

        if(arr[i] == arr[i + 1]){

            // Брояч за броя повтарящи се числа
            unsigned int count = 0;

            // Броим колко еднакви елемнта има без първия тъй като почваме от него
            for(; count < size - i - 1; count++)
                if(arr[i + count] != arr[i + count + 1]) break;

            // Добавяме още едно заради първия елемент
            count++;

            // Преместваме елементите напред на мястото на повтарящите се
            for(unsigned k = 0; k < size - i - 1; k++)
                arr[i + k] = arr[i + k + count];
            
            // Премахваме от size-а колкото елемента сме изтрили
            size -= count;

        }

    }

}

void printArrayWithoutDuplicates(int arr[], const unsigned int &size){

    bool hasDuplicate = false;

    for(unsigned int i = 0; i < size - 1; i++){

        if(arr[i] == arr[i + 1]){

            hasDuplicate = true;
            continue;

        }

        if(!hasDuplicate) std::cout << arr[i] << ' ';
        hasDuplicate = false;

    }

    if(!hasDuplicate) std::cout << arr[size - 1];
    std::cout << '\n';

}

int main(){

    unsigned int size = 10;
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 6, 7};

    printArrayWithoutDuplicates(arr, size);

    removeDuplicates(arr, size);

    std::cout << size << '\n';

    for(unsigned int i = 0; i < size; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

}