#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

// ---------------------------------- Generic Pathfinding ----------------------------------
const size_t SIZE = 4;

bool isValidMove(const int matrix[][SIZE], const bool used[][SIZE], const size_t &x, const size_t &y){

    return x < SIZE && y < SIZE && matrix[x][y] == 0 && !used[x][y];

}

bool genericPathFinder(int matrix[][SIZE], bool used[][SIZE], const size_t &sx, const size_t &sy, const size_t &ex, const size_t &ey){

    if(!isValidMove(matrix, used, sx, sy)) return false;
    if(sx == ex && sy == ey) return true;

    used[sx][sy] = true;

    bool result = genericPathFinder(matrix, used, sx + 1, sy, ex, ey)
        || genericPathFinder(matrix, used, sx, sy + 1, ex, ey)
        || genericPathFinder(matrix, used, sx - 1, sy, ex, ey)
        || genericPathFinder(matrix, used, sx, sy - 1, ex, ey);
    
    used[sx][sy] = false;

    return result;

}

void showPathFinding(){
    
    int matrix[4][4] = {

        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}

    };

    bool used[4][4] = {false};

    size_t sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    cout << std::boolalpha << genericPathFinder(matrix, used, sx, sy, ex, ey) << '\n';

}

// ---------------------------------- Task 1 ----------------------------------
void task1(){

    int n = 0;
    cin >> n;
    cin.ignore();

    char* arr = new char[n + 1];

    cin.getline(arr, n);

    int count = 1, max = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        if(arr[i] == arr[i + 1]){
            count++;
        }
        else{
            if(count > max) max = count;
            // Алтернативен вариант за намиране на max, който аз ползвам.
            // max = std::max(count, max);
            count = 1;
        }
    }
    
    cout << max << '\n';

    delete[] arr;

}

// ---------------------------------- Task 2 ----------------------------------
bool hasPath(int **matrix, const size_t &n, const size_t &sx, const size_t &sy, const int &targetValue){

    if(matrix[sx][sy] == targetValue) return true;
    if(sx >= n || sy >= n || matrix[sx][sy] >= 10 || matrix[sx][sy] > targetValue) return false; 
    return hasPath(matrix, n, sx + 1, sy, targetValue) || hasPath(matrix, n, sx, sy + 1, targetValue);

}

void task2(){

    size_t n;
    cin >> n;

    int **matrix = new int*[n];
    for(size_t i = 0; i < n; ++i){

        matrix[i] = new int[n];
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];

    }

    size_t sx, sy, targetValue;
    cin >> sx >> sy >> targetValue;

    cout << std::boolalpha << hasPath(matrix, n, sx, sy, targetValue);

}

// ---------------------------------- Task 3 ----------------------------------
int function(int x, int cnt = 1){

    if(cnt == 35) return x;
    if(x % 2 == 0) return function(x / 2, cnt + 1);
    return function (3 * x + 1, cnt + 1);

}

void task3(){

    int x;
    cin >> x;

    cout << function(x) << '\n';

}

// ---------------------------------- Task 4 ----------------------------------
void task4(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int marmalad = 0, borovinki = 0, shipki = 0;

    for (int i = 0; i < n / 8; i++)
    {
        int temp = 0;
        for (int j = 3; j < 7; j++)
        {   
            temp *= 10;
            temp += arr [8 * i + j];
        }
        if(temp % 7 == 0) marmalad++;
        else if(temp % 13 == 0) borovinki++;
        else if(temp % 17 == 0) shipki++;

    }

    cout << marmalad << ' ' << borovinki << ' ' << shipki << '\n';

    delete[] arr;

}

int main(){

    // showPathFinding();
    // task1();
    // task2();
    // task3();
    // task4();

}