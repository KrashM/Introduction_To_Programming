#include <iostream>

const size_t CAPACITY = 100;

bool IsValidIndex(size_t const i, size_t const j, size_t const sizeX, size_t const sizeY){
    return i < sizeY && j < sizeX;
}

void PrintInSpiral(int matrix[][CAPACITY], size_t const sizeX, size_t const sizeY){

    bool visited[CAPACITY][CAPACITY];

    size_t indexRow = 0, indexColomn = 0;
    int directionX = 1, directionY = 0;

    for(size_t i = 0; i < sizeX * sizeY; ++i){

        std::cout << matrix[indexRow][indexColomn] << ' ';
        visited[indexRow][indexColomn] = true;

        if(!IsValidIndex(indexRow + directionY, indexColomn + directionX, sizeX, sizeY)
            || visited[indexRow + directionY][indexColomn + directionX]){

            if(directionX != 0){

                directionY = directionX;
                directionX = 0;

            }
            else if(directionY != 0){

                directionX = -directionY;
                directionY = 0;

            }

        }

        indexRow += directionY;
        indexColomn += directionX;

    }

}

int main(){

    int matrix[CAPACITY][CAPACITY];
    size_t sizeX, sizeY;
    std::cin >> sizeX >> sizeY;

    if(sizeX >= CAPACITY || sizeY >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < sizeY; ++i)
        for(size_t j = 0; j < sizeX; ++j)
            std::cin >> matrix[i][j];

    PrintInSpiral(matrix, sizeX, sizeY);

    return 0;

}