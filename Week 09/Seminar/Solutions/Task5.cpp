#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

int main(){

    size_t n;
    bool hasDuplicate;
    cin >> n;

    char *string = new char[n + 1];
    cin >> string;

    for(size_t i = 0; i < n; ++i){
    
        hasDuplicate = false;

        for(size_t j = 0; j < n; ++j){

            if(i == j) continue;
            hasDuplicate = string[i] == string[j] || hasDuplicate;

        }

        if(!hasDuplicate){

            cout << "First non-repeating character is " << string[i] << '\n';
            break;

        }

    }

    if(hasDuplicate)
        cout << "Either all characters are repeating or string is empty\n";

}