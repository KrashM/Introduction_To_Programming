#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

int compareLenghts(char *element, int &startIndex, int &lenght){

    int firstLenght = 0;
    bool fillFirst = true;

    for(int i = 0; i < strlen(element); i++)
        if(fillFirst)
            if(element[i] != '-')
                firstLenght++;
            else{
                
                startIndex = i + 1;
                fillFirst = false;

            }
        else
            lenght++;

    return lenght - firstLenght;

}

bool isLetter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

bool isSymbol(char c){
    return !(isLetter(c) || isDigit(c) || c == '\n');
}

bool hasSpaceBeforeIt(char c){
    return c == '-' || c == '+' || c == '-' || c == '/' || c == '*' || c == '>' || c == '<' || c == '=' || c == '(';
}

bool hasSpaceAfterIt(char c){
    return !(isLetter(c) || isDigit(c) || c == '(');
}

void move(char* &text, int &textSize, int index, int spaces){

    for(int i = textSize; i >= index; i--)
        text[i + spaces] = text[i];
    textSize += spaces;

}

void insert(char* &text, int &textSize, char c, int index){

    move(text, textSize, index, 1);
    text[index] = c;

}

void insert(char* &text, int &textSize, char* element, int index){

    int startIndex, lenght = 0, difference = compareLenghts(element, startIndex, lenght);
    move(text, textSize, index, difference);
    
    for(int i = 0; i < lenght; i++)
        text[index + i] = element[startIndex + i];

}

bool isCorrectElement(char* &text, char* element, int index){

    for(int i = 0; element[i] != '-'; i++)
        if(text[index + i] != element[i]) return false;
    return true;

}

bool isCorrectForm(char* &text, char* element, int index){

    int startIndex, lenght = 0;
    compareLenghts(element, startIndex, lenght);
    for(int i = 0; i < lenght; i++)
        if(text[index + i] != element[startIndex + i]) return false;
    return true;

}

void fullStops(char* &text, int &textSize){

    const char dot = '.';

    for(int i = 0; i < textSize; i++)
        if(text[i] == '\n' && text[i - 1] != dot)
            insert(text, textSize, dot, i);

    if(text[textSize] != dot)
        if(text[textSize] == '\"')
            insert(text, textSize, dot, textSize);
        else
            insert(text, textSize, dot, textSize + 1);

}

void spaces(char* &text, int &textSize){

    const char space = ' ';
    bool isOpeningBrace = true;

    for(int i = 1; i < textSize - 1; i++)
        if(isSymbol(text[i]) && text[i] != space){

            if(text[i] == '\"'){

                if(isOpeningBrace && text[i - 1] != space)
                    insert(text, textSize, space, i);
                if(!isOpeningBrace && text[i + 1] != space)
                    insert(text, textSize, space, i + 1);

                isOpeningBrace = !isOpeningBrace;

            }
            else{

                if(hasSpaceAfterIt(text[i]) && text[i + 1] != space)
                    insert(text, textSize, space, i + 1);
                
                if(hasSpaceBeforeIt(text[i]) && text[i - 1] != space)
                    insert(text, textSize, space, i);

            }

        }

}

void dictionaryCorrections(char* &text, char **dictionary, int &textSize, int dictionarySize){

    for(int i = 0; i < textSize + 1; i++)
        for(int j = 0; j < dictionarySize; j++)
            if(text[i] == dictionary[j][0])
                if(isCorrectElement(text, dictionary[j], i) && !isCorrectForm(text, dictionary[j], i))
                    insert(text, textSize, dictionary[j], i);

}

void autoCorrect(char* &text, char **dictionary, int textSize, int dictionarySize){

    dictionaryCorrections(text, dictionary, textSize, dictionarySize);

    fullStops(text, textSize);

    spaces(text, textSize);

    // Set last element to be terminating 0
    textSize += 1;
    text[textSize] = '\0';

}

void inputHandle(){

    int textSize, dictSize, index = 0;

    // Insert text size
    cin >> textSize;
    cin.get();
    // Validate text size
    if(textSize < 1 || textSize > 1024)
        throw -1;

    // Insert text
    char *text = new char[textSize];
    for(int i = 0; i <= textSize; i++)
        text[i] = cin.get();

    // Insert dictionary size
    cin >> dictSize;
    cin.get();
    // Validate dictionary size
    if(dictSize < 0 || dictSize > 128)
        throw -2;

    // Insert dictionary
    char **dictionary = new char*[dictSize];
    for(int i = 0; i < dictSize; i++){
        
        dictionary[i] = new char[101];
        cin.getline(dictionary[i], 100);

    }

    autoCorrect(text, dictionary, textSize, dictSize);
    cout << text << '\n';

    // Не съм си изчистил паметта. :(

}

int main(){

    try{

        inputHandle();
        
    }
    catch(int ex){

        if(ex == -1) cout << "Incorrect text size was inserted!\n";
        if(ex == -2) cout << "Incorrect dictionary size was inserted!\n";

    }

}
/*
533
Once upon a time there lived in a certain village a little country girl, the pritiest creature who was ever seen. Her mother was excessively fond of her; and her grandmother doted on her still more.This good woman had a little red riding hood made for her. It suited the girl so extremely well that everybody called her little red riding hood.
One day her mother, having made some cakes, said to her,"Go, my dear, and see how your grandmother is doing, for I hear she has been very ill. Take her a cake, and this little pot of leafes"
4
stil-still
pritiest-prettiest
little red riding hood-Little Red Riding Hood
leafes-leaves

*/