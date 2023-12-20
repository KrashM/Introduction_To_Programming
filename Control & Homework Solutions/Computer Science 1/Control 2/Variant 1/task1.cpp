#include <iostream>

const size_t COLS=10, ROWS=5;

bool AreSymtrical(double row1[],double row2[]){
    for(int i=0;i<COLS;i++){
        if(row1[i]!=row2[COLS-i-1]){
            return false;
        }
    }
    return true;
}

bool MatrixHasSymetricalRows(double matrix[][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=i+1;j<ROWS;j++){
            if(AreSymtrical(matrix[i],matrix[j])){
                return true;
            }
        }
    }
    return false;
}

int main(){
    double matrix[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            std::cin>>matrix[i][j];
        }
    }
    std::cout<< (MatrixHasSymetricalRows(matrix) ? "Yes" : "No")<<std::endl;
}
/*
  0.754    1.235   -2.567    3.890   -4.321   -0.456    2.123    5.678   -1.234    0.789
  6.543   -3.210    2.345   -0.876    4.567    1.234   -5.678    0.987   -2.345    3.210
  1.111   -4.432    0.555    3.333    2.222   -1.111    4.444   -0.999    5.555   -2.222
 -3.789    2.456   -1.123    4.678   -0.234    3.789   -2.456    1.123    0.234   -4.678
  5.432   -0.567    3.210   -1.654    2.789   -5.432    0.567   -3.210    1.654   -2.789
No

  0.754    1.235   -2.567    3.890   -4.321   -0.456    2.123    5.678   -1.234    0.789
  6.543   -3.210    2.345   -0.876    4.567    1.234   -5.678    0.987   -2.345    3.210
  1.111   -4.432    0.555    3.333    2.222   -1.111    4.444   -0.999    5.555   -2.222
  3.210   -2.345    0.987   -5.678    1.234    4.567   -0.876    2.345   -3.210    6.543
  5.432   -0.567    3.210   -1.654    2.789   -5.432    0.567   -3.210    1.654   -2.789
Yes
*/