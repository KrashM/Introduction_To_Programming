<h1>Рекурсивни алгоритми</h1>

<h3>1. Кулите на Ханой</h3>

```c++
void TowerOfHanoi(const unsigned n, const char from_rod, const char to_rod, const char aux_rod)
{
    if(n == 0)
    {
        return;
    }
    TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << '\n';
    TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
```

<h3>2. Намиране на пермутации</h3>

```c++
void Permute(char * const str, const size_t left, const size_t right)
{
    if(left == right)
    {
        std::cout << str << '\n';
        return;
    }
    for(size_t i = left; i <= right; i++)
    {
        std::swap(str[left], str[i]);
        Permute(str, left + 1, right);
        std::swap(str[left], str[i]);
    }
}
```

<h3>3. Намиране на всички подмножества на множество</h3>

```c++
void PrintSubset(const char * const A, const size_t size, char * const subset, const size_t subsetSize, const size_t index)
{
    std::cout << subset << '\n';

    for(size_t i = index; i < size; ++i)
    {
        subset[subsetSize] = A[i];
        PrintSubset(A, size, subset, subsetSize + 1, i + 1);
        subset[subsetSize] = '\0';
    }
}
```

<h3>4. Запълване не полета</h3>

- В частност давам пример с **`N Queen Problem`**

```c++
bool IsSafe(const bool board[][ROWS], const size_t row, const size_t col)
{
    for(size_t i = 0; i < col; ++i)
    {
        if(board[row][i])
        {
            return false;
        }
    }

    for(size_t i = 0; i < row && i < col; ++i)
    {
        if(board[i][i])
        {
            return false;
        }
    }

    for(size_t i = 0; i < col && i < row; ++i)
    {
        if(board[ROWS - i - 1][i])
        {
            return false;
        }
    }

    return true;
}

bool SolveNQ(bool board[][ROWS], const size_t col)
{
    if(col >= ROWS)
    {
        return true;
    }

    for(size_t i = 0; i < ROWS; ++i)
    {
        if(IsSafe(board, i, col))
        {
            board[i][col] = true;

            if(SolveNQ(board, col + 1))
            {
                return true;
            }

            board[i][col] = false;
        }
    }

    return false;
}
```

<h3>5. DFS - алгоритъм за търсене на път в дълбочина</h3>

```c++
bool IsValidMove(const bool * const * const map, const size_t n, const size_t x, const size_t y)
{
    return x < n && y < n && !map[x][y];
}

bool HasPath(bool * const * const map, const size_t n, const size_t sx, const size_t sy, const size_t ex, const size_t ey){

    if(!IsValidMove(map, n, sx, sy))
    {
        return false;
    }
    if(sx == ex && sy == ey)
    {
        return true;
    }

    map[sx][sy] = true;

    bool result = HasPath(map, n, sx + 1, sy, ex, ey)
        || HasPath(map, n, sx, sy + 1, ex, ey)
        || HasPath(map, n, sx - 1, sy, ex, ey)
        || HasPath(map, n, sx, sy - 1, ex, ey);

    map[sx][sy] = false;

    return result;

}
```

<h1>Задачи</h1>

**Задача 1** Да се напише рекурсивна функция, която по подадени N и M, размерите на площад. Намерете колко най-малко плочки ще са нужни да запълнят площада, ако плочките са размери 2^n x 2^n.

*Вход: 5 6*<br>
*Изход: 9*<br>
![](https://media.geeksforgeeks.org/wp-content/uploads/Screenshot-from-2017-10-13-19-07-16.png)

**Задача 2** Да се напише рекурсивна функция, която по подадено цяло положително число n, принтира всички възможни двоични низове, без съседни единици.

*Вход: 4*<br>
*Изход: 0000 0001 0010 0100 0101 1000 1001 1010*

**Задача 3** Да се напише рекурсивна функция, която намира валиден път между две точки. На функцията ще бъде подадена матрица NxN, картата по която трябва да се движим. Ако на дадена позиция има 1, това означава че не можем да минаваме през тази клетка. Движенията може да се случват само в 4те кардинални посоки(без диагоналите).

*Вход: 8*</br>
*[0, 0, 1, 0, 1, 0, 0, 1]*</br>
*[0, 0, 1, 0, 0, 1, 0, 1]*</br>
*[0, 1, 0, 0, 0, 1, 0, 1]*</br>
*[0, 1, 0, 0, 0, 1, 0, 1]*</br>
*[0, 0, 0, 0, 1, 1, 0, 1]*</br>
*[0, 1, 0, 1, 1, 1, 0, 1]*</br>
*[0, 1, 0, 1, 0, 1, 0, 1]*</br>
*[0, 1, 1, 0, 1, 1, 0, 1]*</br>

*Вход: (0, 0) - (0, 3) Изход: true*</br>
*Вход: (0, 0) - (6, 4) Изход: false*

**Задача 5** Имайки NxN поле и кон поставен в горният ляв ъгъл на полето. Да се напише рекурсивна функция, която мърдайки конят по правилата на шаха, посещава всяка една клетка. Да се изпринтира поредността, в която всяка клетка е посетена.

*Вход: 8*</br>
*Изход:*</br>
*0  59  38  33  30  17   8  63*</br>
*37  34  31  60   9  62  29  16*</br>
*58   1  36  39  32  27  18   7*</br>
*35  48  41  26  61  10  15  28*</br>
*42  57   2  49  40  23   6  19*</br>
*47  50  45  54  25  20  11  14*</br>
*56  43  52   3  22  13  24   5*</br>
*51  46  55  44  53   4  21  12*

**Задача от изпит 2021-2022**
Ясен Яворов има малък бизнес за покупка и продажба на дърва
за огрев. С камиона си той обслужва малкото село Квадратово, като разнася
дърва за жителите му. Селото се слави с изключително правилната си
архитектура: къщите в него образуват квадрат, като от всяка къща има улица
към съседите ѝ на север, юг, изток и запад (освен тези в края на селото,
разбира се). Всяка седмица Ясен получава заявки от съселяните си, които
надлежно записва в компютъра си като квадратна матрица map от цели числа с
размерност N × N (N < 128), в която клетките означават къщите, а числата
означават заявките на всяка къща. Положително число K означава, че
стопаните на къщата искат да продадат K кубика дърва, а отрицателно число
-L означава, че те искат да купят L кубика дърва. Ясен иска да планира
обиколката си като започне от къщата си на позиция (homeRow, homeColumn), да
стигне до къщата на баба си (която също му е клиент!) на позиция (grannyRow,
grannyColumn) и да се върне обратно в къщата си. Той се чуди дали има начин
да направи това като:
● по пътя изпълнява точно заявките на къщите през които минава – понеже
Ясен не иска клиентите му да се обидят и да го оценят с една звезда, той
не може да ги подмине без да изпълни заявката им и винаги иска да я
изпълни изцяло (т.е. за цялото количество);
● на връщане той не иска да минава обратно през клиенти, чиито заявки
вече е изпълнил, за да оптимизира пътя си;
● числото в къщата на Ясен означава с колко кубика дърва той товари
камиона си първоначално;
● не иска да претоварва камиона си повече от максималния му капацитет,
зададен с положителното цяло число maxVolume;
● не иска да се окаже в ситуация, в която минава през къща, която иска да
купи дърва, а той не носи достатъчно.
Помогнете на Ясен като реализирате функция foundRoute, която приема
описаните по-горе параметри и връща като резултат булева стойност, указваща
дали в селото има път, който удовлетворява изискванията на Ясен.

Упътване: използвайте рекурсия за търсене с връщане назад (backtracking)
като записвате товара на камиона на всяка стъпка.
Бонус (0,5): Функцията да извежда и намерения път.
![](https://i.ibb.co/x1YGL3s/image.png)