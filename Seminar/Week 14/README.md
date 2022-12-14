<h1> Файлове </h1>

<h1> 1. Кога се използват? </h1>

- Ако искаме да четем вход към програмата автоматично.
- Ако правим logging система, която да записва грешките.
- Ако трябва да пазим информация от програмата за по-дълго време.
- И още други...

<h1> 2. Четене от файл </h1>

```c++
#include <fstream> // библиотеката, която ще ни трябва

using std::ifstream; // Съкратено от input file stream

int main()
{

    // Търси файл с това име в текущата директория на програмата.
    ifstream inFile("myInputFile.txt");

    if(!inFile.is_open())
    {
        // Имаме проблем с отварянето на файла!
        return -1;
    }

    int x;

    inFile >> x; // Прочита един int от файла.

    // Всеки файл трябва да се затвори след като приключим да го използваме.
    inFile.close();

}
```

<h1> 3. Писане към файл </h1>

```c++
#include <fstream> // Същата библиотека

using std::ofstream; // Съкратено от output file stream

int main()
{

    // Търси файл с това име в текущата директория на програмата.
    // Ако не намери такъв го създава.
    ofstream outFile("myOutputFile.txt");

    if(!outFile.is_open())
    {
        // Имаме проблем с отварянето на файла!
        return -1;
    }

    int x = 10;

    outFile << x; // Записва x в файла

    // Отново трябва да си затворим файла.
    outFile.close();

}
```

<h1> Задачи </h1>

**Задача 1** Да се напише рекурсивна функция, която намира максимален елемент в масив.

**Задача 2** Да се напише рекурсивна функция, която сумира елементите на масив.

**Задача 3** Да се направи рекурсивна функция, която принтира всички subset-ове на даден set.

**Задача 4** Да се реализира "[The eight queen problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle)", само че разписана за n кралици.
