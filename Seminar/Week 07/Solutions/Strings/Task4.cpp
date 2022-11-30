#include <iostream>
#include <cstring>

int countkDist(const char str[], const unsigned int size, const unsigned int k){

    int res = 0, cnt[26], dist_count;
 
    for(int i = 0; i < size; i++){

        dist_count = 0;
        memset(cnt, 0, sizeof(cnt));

        for(int j = i; j < size; j++){

            if(!cnt[str[j] - 'a']++) dist_count++;
            if(dist_count == k) res++;
            if(dist_count > k) break;

        }

    }

    return res;

}

int main(){

    const char str[] = "abcbaa";
    int k;
    std::cin >> k;
    std::cout << "Total substrings with exactly "
        << k <<" distinct characters :"
        << countkDist(str, sizeof(str) - 1, k) << '\n';

}