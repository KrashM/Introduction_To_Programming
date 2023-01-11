#include <iostream>
#include <fstream>
#include <cstring>

using std::ifstream;
using std::ofstream;
using std::nothrow;
using std::cout;

struct dictPair{
    char wrong[101], right[101];
    int difference; // Пазя разликата в дължината на думите.
};

// ------------------------------------------------------------------
// Функции за проверяване на символи
bool isLetter(const char &ch){
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}


bool isDigit(const char &ch){
    return '0' <= ch && ch <= '9';
}

bool isSymbol(const char &ch){
    return !(isLetter(ch) || isDigit(ch) || ch == '\n');
}

bool hasSpaceBeforeIt(const char &ch){
    return ch == '-' || ch == '(';
}

bool hasSpaceAfterIt(const char &ch){
    return !(isLetter(ch) || isDigit(ch) || ch == '(');
}
// ------------------------------------------------------------------

// Добавяме място в текста
void moveForward(char *text, size_t &textSize, const size_t &index, const size_t &spaces){

    for(size_t i = 0; i < textSize - index; ++i)
        text[textSize - i - 1 + spaces] = text[textSize - i - 1];
    textSize += spaces;

}

// Премахваме място в текста
void moveBackward(char *text, size_t &textSize, const size_t &index, const size_t &spaces){

    for(size_t i = index; i <= textSize; ++i)
        text[i] = text[i + spaces];
    textSize -= spaces;

}

// Вкарваме един символ(използваме за '.' и ' ').
void insert(char *text, size_t &textSize, const char &ch, const size_t &index){

    moveForward(text, textSize, index, 1);
    text[index] = ch;

}

// Вкарваме думи от речника
void insert(char *text, size_t &textSize, const dictPair &pair, const size_t &index){

    // Ако грешната дума е по-кратка от правилната изместваме напред
    // В противен случай изместваме назад
    if(pair.difference > 0) moveForward(text, textSize, index, pair.difference);
    else moveBackward(text, textSize, index, -pair.difference);

    // Слагаме правилната дума в текста
    for(size_t i = 0; i < strlen(pair.right); i++)
        text[index + i] = pair.right[i];

}

// Проверявам дали това е "правилната" грешна дума.
bool isWrongWord(const char *text, const char *wrong, const size_t &index){

    for(size_t i = 0; i < strlen(wrong); i++)
        if(text[index + i] != wrong[i]) return false;
    return true;

}

// Функция да коригира думите в текста
void correctWords(char *text, size_t &size, const dictPair *dictionary, const size_t &dictSize, ofstream &log){

    // Обикалям символ по символ
    for(size_t i = 0; i < size; ++i)
        // Въртя през всички елементи на речника
        for(size_t j = 0; j < dictSize; ++j)
            // За всеки символ проверяваме дали съвпада с първата буква на всяка дума в речника
            if(text[i] == dictionary[j].wrong[0])
                // Ако съвпаднат проверявам дали има буква преди и след думата и ако всичко е наред коригирам.
                if((i != 0 && !isLetter(text[i - 1])) && isWrongWord(text, dictionary[j].wrong, i) && !isLetter(text[i + strlen(dictionary[j].wrong)])){

                    insert(text, size, dictionary[j], i);
                    log << "Corrected word -> " << dictionary[j].wrong << " to " << dictionary[j].right << '\n';

                }

}

// Функция за оправяне на точките
void fullStops(char *text, size_t &textSize, ofstream &log){

    const char dot = '.';

    for(size_t i = 0; i < textSize; i++)
        // Ако стигнем до край на реда и няма точка добавяме точка.
        if(text[i] == '\n' && text[i - 1] != dot){

            insert(text, textSize, dot, i);
            log << "Added fullstop at -> " << i << '\n';

        }

    // Ако края на текста няма точка добавяме
    if(text[textSize] != dot){

        // Ако имаме кавичка накрая на текста добавяме
        if(text[textSize] == '\"') insert(text, textSize, dot, textSize);
        else insert(text, textSize, dot, textSize);

        log << "Added fullstop at -> " << textSize << '\n';

    }

}

// Функция за оправяне на празните места
void spaces(char *text, size_t &textSize, ofstream &log){

    const char space = ' ';
    bool isOpeningBrace = true;

    for(int i = 1; i < textSize - 1; i++)
        // Проверявам дали съм стигнал някакъв символ и ако да проверявам дали е различен от ' ' и тогава добавям.
        if(isSymbol(text[i]) && text[i] != space){

            // Проверявам каква кавичка е.
            if(text[i] == '\"'){

                // Ако е отваряща добавяме пред.
                if(isOpeningBrace && text[i - 1] != space){
                    
                    insert(text, textSize, space, i);
                    log << "Added space at -> " << i << '\n';

                }

                // Ако е отваряща добавяме след.
                if(!isOpeningBrace && text[i + 1] != space){
                    
                    insert(text, textSize, space, i + 1);
                    log << "Added space at -> " << i + 1 << '\n';

                }
                
                // Сменям типа на кавичката.
                isOpeningBrace = !isOpeningBrace;

            }
            else{

                // Проверявам правилата дали има ' ' след този символ.
                if(hasSpaceAfterIt(text[i]) && text[i + 1] != space){
                    
                    insert(text, textSize, space, i + 1);
                    log << "Added space at -> " << i + 1 << '\n';

                }

                // Проверявам правилата дали има ' ' пред този символ.
                if(hasSpaceBeforeIt(text[i]) && text[i - 1] != space){
                    
                    insert(text, textSize, space, i);
                    log << "Added space at -> " << i << '\n';

                }

            }

        }

}

void autoCorrect(char *text, size_t textSize, dictPair *dictionary, const size_t &dictSize, ofstream &log){

    correctWords(text, textSize, dictionary, dictSize, log);
    fullStops(text, textSize, log);
    spaces(text, textSize, log);

}

// Разделяме реда на речника в две отделни думи
dictPair separate(const char *dictElement){

    dictPair newElement;

    // Намираме дължината на първия string, за да може да сложим '\0' отзад.
    // Ползвам pointer arithmetic, за да намеря разликата.
    // Намирам първото срещане на '-' и от този адрес изваждам началото.
    size_t firstSize = strstr(dictElement, "-") - dictElement;

    // Копирам първата дума от общия ред
    strncpy(newElement.wrong, dictElement, firstSize);
    newElement.wrong[firstSize] = '\0';

    // Копирам втората дума от общия ред
    strncpy(newElement.right, dictElement + firstSize + 1, strlen(dictElement) - firstSize);

    // Намирам разликата в дължината на двете думи
    newElement.difference = strlen(newElement.right) - strlen(newElement.wrong);

    return newElement;

}

void inputText(char *&text, size_t &textSize, ifstream &input){

    input >> textSize;
    input.ignore();

    text = new(nothrow) char[4 * 1024 * 1024];
    if(text == nullptr) throw 1;

    for(size_t i = 0; i < textSize; ++i)
        text[i] = input.get();
    text[textSize] = '\0';

}

void inputDictionary(dictPair *&dictionary, size_t &dictSize, ifstream &input){

    input >> dictSize;
    input.ignore();

    dictionary = new(nothrow) dictPair[dictSize];
    if(dictionary == nullptr) throw 1;

    char dictElement[101];

    for(size_t i = 0; i < dictSize; ++i){

        input.getline(dictElement, 101);
        dictionary[i] = separate(dictElement);

    }

}

int main(){

    size_t textSize, dictSize;
    char *text;
    dictPair *dictionary;

    ifstream input("input.txt");
    ofstream output("output.txt"), log("errors.txt");

    if(!input.is_open()){

        cout << "Error opening the file\n";
        return -1;

    }

    try{

        inputText(text, textSize, input);
        inputDictionary(dictionary, dictSize, input);

    }
    catch(const int &ex){

        cout << "Problem with memory\n";
        return -1;

    }

    autoCorrect(text, textSize, dictionary, dictSize, log);

    output << text;

    input.close();
    output.close();

    delete[] text;
    delete[] dictionary;

}