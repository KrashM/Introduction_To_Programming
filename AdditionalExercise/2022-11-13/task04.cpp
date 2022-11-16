#include <iostream> 
#include <cstring>

int main () {
    const int SIZE = 2048;

    char str[SIZE], str2[SIZE], str3[SIZE];
    int j = 0;

    std::cin.getline(str, SIZE);
    const int len = strlen(str);
    int n = len;

    str3[len] = '\0';

    for (int i = 0; i < len; i++) {

        if (str[i] == ' ') {

            str2[j] = '\0';

            while (str3[n] != ' ' && str3[n] != '\0') {
                n--;
            }
            n--;

            for (int k = 0; k < j; k++){
                str3[n - j + k + 1] = str2[k];
            }
            if (n - j >= 0) {
                str3[n - j] = ' '; 
            }
            j = 0;

        } else {

            str2[j] = str[i];
            j++;
        }
    }

    str2[j] = '\0';

            while (str3[n] != ' ' && str3[n] != '\0') {
                n--;
            }
            n--;

            for (int k = 0; k < j; k++){
                str3[n - j + k + 1] = str2[k];
            }
            if (n - j >= 0) {
                str3[n - j] = ' '; 
            }

    std::cout << str3 << '\n';

    return 0;
}