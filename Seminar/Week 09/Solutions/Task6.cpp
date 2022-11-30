#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

int main(){

    size_t n;
    cin >> n;
    
    char *result = new char[n + 1];
    cin >> result;

    char *temp;

    for(size_t i = 0; i < 2; ++i){

        cin >> n;
        temp = new char[n + 1];
        cin >> temp;

        for(size_t j = 0; j < n; ++j)
            if(temp[j] != result[j]) result[j] = '\0';

        delete[] temp;

    }

    cout << result << '\n';

    delete[] result;
    
}