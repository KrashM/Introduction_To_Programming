#include<iostream>

unsigned progression(int a[], unsigned n);

int main(){

    // int a[] = {1, 3, 1, 2, 3, 1};
    // int a[] = {4, 3, 2, 1};
    int a[] = {1, 2, 3, 4, 2, 2, 2, 3, 5, 6, 8, 12, 13};
    unsigned lenght = progression(a, sizeof(a) / 4);

    std :: cout << lenght << '\n';

    return 0;

}

unsigned progression(int a[], unsigned n){

    unsigned longestSequenceLenght = 1;
    unsigned currentSequenceLenght = 1;

    for(int i = 1; i < n; i++){

        if(a[i] > a[i - 1]) currentSequenceLenght++;
        else currentSequenceLenght = 1;

        if(currentSequenceLenght > longestSequenceLenght) longestSequenceLenght = currentSequenceLenght;

    }

    return longestSequenceLenght;

}