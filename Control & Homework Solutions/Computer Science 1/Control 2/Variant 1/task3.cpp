#include <iostream>
#include <cstring>

const size_t MAX_SIZE=100;

void zip(char *a, char *b, char *result)
{
    int index = 0, index1 = 0, index2 = 0;
    int n1 = strlen(a), n2 = strlen(b);
    while (index1 < n1 && index2 < n2){

        while (index1 < n1 && a[index1] != ' '){
            result[index] = a[index1];
            index1++;
            index++;
        }
        result[index]=' ';
        index++;
        index1++;

        
        while (index2 < n2 && b[index2] != ' '){
            result[index] = b[index2];
            index2++;
            index++;
        }
        result[index]=' ';
        index++;
        index2++;
    }

    result[index]=0;
    if(index1>=n1)
        strcat(result,b+index2);
    else if(index2>=n2)
        strcat(result,a+index1);

}

int main()
{
    char a[MAX_SIZE] = "Study programming it's very easy",
         b[MAX_SIZE] = "computer because not"; 
    char res[MAX_SIZE];
    zip(a,b,res);
    std::cout<<res<<std::endl;
}
