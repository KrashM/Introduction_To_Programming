<h1> Аргументи на `main`, записи (структури)</h1>

## Задачи

### Задача 1:
Като използвате аргументите на `main`, сортирайте в лексикографски ред и изведете на екрана символните низове подадени през терминала. 

**Пример:**

```
./task1.exe zac voe morty rick joe bob aladin
```

**Изход:**

```
aladin bob joe morty rick voe zac
```

### Задача 2:
Въведете в терминала две числа и намерете тяхната сума. Изведете резултата на екрана. За целта използвайте аргументите на `main`. Ако те са повече от 2, изведете съобщение за невалиден вход.

**Пример:**

```
./task2.exe 5
```

**Изход:**

```
Invalid input
```

**Пример:**

```
./task2.exe 5 13  
```

**Изход:**

```
18
```

**Пример:**

```
./task2.exe 5 13 2
```

**Изход:**

```
Invalid input
```


### Задача 3:
Да се направи запис на двойка координати (`Pair`). Да се въведат 3 точки и да се провери дали образуват триъгълник, и ако да, да се намери периметъра на триъгълника.

**Пример:**

```
А(x,y): 1 1
B(x,y): 3 1
C(x,y): 2 3
```

**Изход:**

```
Perimeter: 6.47214
```

### Задача 4:
Да се направи запис правоъгълник, чиито страни са успоредни на координатните оси. Той се определя от две точки (`Pair`), които представляват двата края на един от диагоналите му, т.е. долна лява и горна дясна точка на правоъгълника. Да се напишат функции, които да намират лицето (`GetArea`) и периметъра на правоъгълника (`GetPerimeter`).

**Пример:**

```
A(x,y): 1 1
B(x,y): 3 3
```

**Изход:**

```
Area: 4
Perimeter: 8
```

### Задача 5:
Нека добавим ново поле в записа на правоъгълника - статичен масив за името му (нека да е с **максимум 10 символа**). Да се въведе статичен масив от правоъгълници, който да се сортира във възходящ ред спрямо лицата им. На изхода да се изведат имената на правоъгълниците и лицата им (вече в сортиран ред).

**Пример:**

```
3
Name: Rect1
Rect1 A: 1 1
Rect1 B: 3 3
Name: Rect2
Rect2 A: 1 1
Rect2 B: 2 2
Name: Rect3
Rect3 A: 1 1
Rect3 B: 4 4
```

**Изход:**

```
Rect2 1
Rect1 4
Rect3 9
```
