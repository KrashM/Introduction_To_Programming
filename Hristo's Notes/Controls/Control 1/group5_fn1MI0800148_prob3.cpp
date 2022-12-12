#include <iostream>
using namespace std;

void secondArrHasPermutationThatIsSubsequenceOfFirstArr(unsigned size1, unsigned size2, char firstArr[], char secondArr[]);

int main(){

    unsigned size1, size2;
    cin >> size1 >> size2;

    char firstArr[size1], secondArr[size2];
    cin >> firstArr >> secondArr;

    try{ secondArrHasPermutationThatIsSubsequenceOfFirstArr(size1, size2, firstArr, secondArr); }
    catch(const int e){ cout << "Incorrect input second string is bigger than the first!" << '\n'; }
    

}

bool isInArr(char c, char arr[], unsigned size){

    for(unsigned i = 0; i < size; i++) if(arr[i] == c) return true;
    return false;

}

void permutate(char *arr, unsigned size){

    char temp = arr[size - 1];
    for(unsigned i = size - 1; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = temp;

}

void secondArrHasPermutationThatIsSubsequenceOfFirstArr(unsigned size1, unsigned size2, char firstArr[], char secondArr[]){

    if(size2 >= size1) throw -1;

    for(unsigned i = 0; i < size2; i++){

        for(unsigned j = 0; j < size1; j++){

            bool flag = false;

            if(firstArr[j] == secondArr[0]){

                flag = true;
                for(unsigned k = 1; k < size2; k++)
                    if(firstArr[j + k] != secondArr[k]){ flag = false; break; }

            }

            if(flag){
                
                cout << "Rotation \""
                    << secondArr
                    << "\" found after deleting "
                    << j
                    << " characters from the start and "
                    << size1 - (j + size2)
                    << " from the end\n";
                return;
                
            }

        }
        permutate(secondArr, size2);

    }

    // Bonus
    // unsigned deletedCharsIndexes[size1 - size2], index = 0;

    // for(unsigned i = 0; i < size1; i++)
    //     if(!isInArr(firstArr[i], secondArr, size2)){

    //         deletedCharsIndexes[index] = i;
    //         index++;

    //     }
    
    // for(unsigned i = 0; i < size2; i++){

    //     for(unsigned j = 0; j < size1; j++){

    //         bool flag = false;

    //         if(firstArr[j] == secondArr[0]){

    //             cout << j << '\n';

    //             flag = true;
    //             for(unsigned k = 1; k < size2; k++){
                    
    //                 for(unsigned l = 0; l < index; l++) if(deletedCharsIndexes[l] == j) j++;

    //                 cout << j << ' ' << k << '\n';

    //                 cout << firstArr[j + k] << ' ' << secondArr[k] << '\n';
    //                 if(firstArr[j + k] != secondArr[k]){ flag = false; break; }

    //             }

    //         }

    //         if(flag){
                
    //             cout << "Rotation \""
    //                 << secondArr
    //                 << "\" found after deleting characters: ";
    //             for(unsigned i = 0; i < index; i++)
    //                 if(i != index - 1) cout << deletedCharsIndexes[i] << ' ';
    //                 else cout << deletedCharsIndexes << '\n';
    //             return;
                
    //         }

    //     }
    //     cout << '\n';
    //     permutate(secondArr, size2);

    // }

    cout << "No rotation found!\n";

}