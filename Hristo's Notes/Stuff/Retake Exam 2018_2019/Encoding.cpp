#include<iostream>
#include<cstring>
#include<map>

void encode(char *s1, char *r1, char *s2, char *&result);

int main(){

    char s1[] = "hello";
    char r1[] = "worrd";
    char s2[] = "love";
    char *result = new char[strlen(s2)+1];
    memset(result, 0, (strlen(s2)+1));

    try{ encode(s1, r1, s2, result); }
    catch(const std :: exception& e){ std :: cerr << e.what() << '\n'; }

    std :: cout << result << '\n';

    return 0;

}

void encode(char *s1, char *r1, char *s2, char *&result){

    if(strlen(s1) != strlen(r1)) throw "Sizes differ";

    std :: map<char, char> encoding;

    for(unsigned i = 0; i < strlen(s1); i++)
        if(encoding.count(s1[i]) && encoding[s1[i]] != r1[i]){
            result = '\0';
            return;

        }
        else encoding.insert({s1[i], r1[i]});
    
    for(unsigned i = 0; i < strlen(s2); i++)
        if(encoding.count(s2[i]) == 1) result[i] = encoding[s2[i]];
        else result[i] = s2[i];

}