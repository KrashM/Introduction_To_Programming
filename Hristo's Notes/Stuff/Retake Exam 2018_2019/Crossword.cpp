#include<iostream>
#include<cstring>

const unsigned dim = 3;
const unsigned maxWordLenght = 9;

bool crossword(char C[dim][dim], char words[][maxWordLenght], unsigned n);

int main(){

    const unsigned n = 5;
    // const unsigned n = 6;

    char C[dim][dim] = {
        {'c', 'a', 't'},
        {'w', 'h', 'o'},
        {'w', 'i', 'n'}
    };

    char words[n][maxWordLenght] = {

        {'h', 'a', 't'},
        {'n', 'i', 'h', 'a', 't'},
        {'w', 'h', 'o'},
        {'w', 'i', 'n'},
        {'n', 'o', 't'},
        // {'c', 'h', 'a', 't'}

    };

    std :: cout << crossword(C, words, n) << '\n';

    return 0;

}

bool canForm(char C[dim][dim], char word[], unsigned index, unsigned i, unsigned j){

    if(index == strlen(word)) return true;

    if(i > 0 && C[i - 1][j] == word[index]) return canForm(C, word, index + 1, i - 1, j);
    if(j > 0 && C[i][j - 1] == word[index]) return canForm(C, word, index + 1, i, j - 1);
    if(i < 2 && C[i + 1][j] == word[index]) return canForm(C, word, index + 1, i + 1, j);
    if(j < 2 && C[i][j + 1] == word[index]) return canForm(C, word, index + 1, i, j + 1);

    return false;

}

bool crossword(char C[dim][dim], char words[][maxWordLenght], unsigned n){

    for(unsigned i = 0; i < n; i++){

        bool flag = false;
        bool formed = true;

        for(unsigned j = 0; j < dim; j++){

            for(unsigned k = 0; k < dim; k++)
                if(words[i][0] == C[j][k])
                    if(!canForm(C, words[i], 1, j, k)) formed = false;
                    else{

                        flag = formed = true;
                        break;

                    }

            if(flag) break;

        }

        if(!formed) return false;

    }

    return true;

}