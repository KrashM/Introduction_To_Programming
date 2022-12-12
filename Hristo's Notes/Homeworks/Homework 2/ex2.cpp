#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

bool longer(int l1, int l2){
    return (l1 > l2) ? true : false;
}

bool isDigit(char digit){
    return digit >= '0' && digit <= '9';
}

bool isLetter(char digit){
    return (digit >= 'A' && digit <= 'Z') || (digit >= 'a' && digit <= 'z');
}

int transformTo10(char digit){
    if(isDigit(digit)) return digit - '0';
    if(isLetter(digit)) return (digit > 'Z') ? digit - 'a' + 10 : digit - 'A' + 10;
}

char transformToK(int digit){
    if(digit < 10) return '0' + digit;
    return 'A' + digit - 10;
}

bool digitIsInNumberSystem(char digit, int k){

    if(isDigit(digit)){
        if(digit - '0' < k) return true;
        else return false;
    }
    else if(isLetter(digit)){
        if((digit > 'Z') ? digit - 'a' : digit - 'A' + 10 < k) return true;
        else return false;
    }
    else return false;
    
}

void reverse(char* &result, int n){

    for(int i = 0; i < n / 2; i++){
        char temp = result[i];
        result[i] = result[n - i - 1];
        result[n - i - 1] = temp;
    }

}

void resize(char* &result, int n){

    char* resize = new char[n + 1];
    for(int i = 0; i < n; i++)
        resize[i] = result[i];
    resize[n] = '\0';
    delete[] result;
    result = resize;

}

char* sumK(char* n, char* m, int k){

    char* result = new char[1010];
    int lenN = strlen(n), lenM = strlen(m), index = 0;

    for(int i = 0; i < lenN; i++)
        if(!digitIsInNumberSystem(n[i], k)) throw -1;
    for(int i = 0; i < lenM; i++)
        if(!digitIsInNumberSystem(m[i], k)) throw -1;
    
    bool nLongerThanM = longer(lenN, lenM);

    int carry = 0, sum;
    
    for(int i = 0; i < ((nLongerThanM) ? lenM : lenN); i++){

        sum = transformTo10((n[lenN - i - 1])) + transformTo10(m[lenM - i - 1]) + carry;
        result[index] = transformToK(sum % k);
        index++;
        carry = sum / k;

    }

    for(int i = ((nLongerThanM) ? lenM : lenN); i < ((nLongerThanM) ? lenN : lenM); i++){
        
        sum = transformTo10(((nLongerThanM) ? n[lenN - i - 1] : m[lenM - i - 1])) + carry;
        result[index] = transformToK(sum % k);
        index++;
        carry = sum / k;

    }

    if(carry > 0){
        
        result[index] = transformToK(carry);
        index++;

    }

    reverse(result, index);
    resize(result, index);
    return result;

}

int main(){

    char *n = new char[1001], *m = new char[1001];
    int k;

    cin >> n >> m >> k;

    try{ cout << sumK(n, m, k) << '\n'; }
    catch(int e){ cout << "Bad input data!\n"; }

    // Пак не съм си изчистил паметта. :(

}