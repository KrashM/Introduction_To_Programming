#include <iostream>

using std::cin;
using std::cout;

bool isValidChar(char c){
    return c == 'g' || c == 'y' || c == 'r';
}

void validate(char input[]){

    for(int i = 0; i < 1024 && input[i] != '\0'; i++)
        if(!isValidChar(input[i]))
            throw -1;
    
}

int robot(char input[], int startIndex){

    int moves = 0;
    const char end = 'r';
    const char skip = 'y';
    const char move = 'g';
    for(int i = startIndex; i < 1024 && input[i] != '\0'; i++){

        if(input[i] == end)
            return moves;
        if(input[i] == skip){
            int before = i;
            for(int j = i + 1; j < 1024 && input[j] != '\0'; j++)
                if(input[j] == move){
                    i = j - 1;
                    break;
                }
            if(i == before)
                return moves;
            moves++;
        }
        if(input[i] == move)
            moves++;

    }

    return moves;

}

int findMostNumberOfMoves(char input[]){

    int max = 0;
    for(int i = 0; i < 1024 && input[i] != '\0'; i++){

        int current = robot(input, i);
        max = (current > max) ? current : max;

    }

    return max;   

}

int main(){

    char input[1024];
    cin >> input;
    try{
        validate(input);
    }
    catch(const int ex){
        cout << "Input was incorrect\n";
    }
    cout << findMostNumberOfMoves(input) << '\n';
    
}

// rgyrggrygr
// ggrrgyrgyr