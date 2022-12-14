# Указатели и динамична памет. Заделяне на едномерни и двумерни масиви.

### Задача :one:
Да се напише функция, която разменя стойностите на две реални числа.

### Задача :two:
Създайте функция `int* createArray(std::size_t size)`, която създава масив от естествени числа по въведена от клавиатурата стойност **n** и връща указател към първия елемент. Ако заделянето на памет е неуспешно, върнете `nullptr`.

### Задача :three:
Да се състави програма, чрез която в едномерен масив се въвеждат естествени цели числа от клавиатурата. Размерът на масива да се въвежда от клавиатурата и да се заделя динамично памет за него. Програмата да изведе общата сума на въведените числа, най-малкото и най-голямото число, като намира посочените стойности в една единствена функция.
```
Вход  
7   
89 -123 45 19 1204 0 112    

Изход   
1346 -123 1204  
```

### Задача :four: 
Заделете в динамичната памет масив с **n** цели числа. Въведете ги от клавиатурата. Пребройте колко от тези числа са 3-цифрени. Заделете нова памет за точно толкова числа и ги запишете в новата памет.

### Задача :five:
Да се състави програма, в която се въвеждат естествени цели числа от клавиатурата. Размерът на масива да се въвежда от клавиатурата и да се заделя динамично памет за него. Програмата да разменя симетричните елементи спрямо средата, като по-малкото число остава в началото на масива, а по-голямото в края.
```
Вход       
7   
189 123 145 196 1204 0 112

Изход    
112 0 145 196 1204 123 189
```

### Задача :six: 
Да се състави програма, която прочита **n** естествени числа от клавиатурата, заделяйки динамична памет за тях, сортира първата половина в нарастващ ред, a втората половина в намаляващ ред и ги отпечатва. Всяко от действията да бъде отделна функция, като съответно подадете половината масив на едната сортираща функция и другата половина от масива на другата. Използвайте *указателна аритметика*.
```
Вход  
7   
189 123 145 196 1000 0 112

Изход    
123 145 189 1000 196 112 0
```

### Задача :seven: 
Да се състави програма, която прочита число **n** и заделя памет за двумерен масив с намаляващ брой елементи на редовете, пълни масива с числа и го отпечатва. Да бъде заделена точно толкова памет, колкото са числата в съответния ред. 
> **Съвет:** използвайте функцията от задача 2. 

```
Вход:
5

Изход
1 2 3 4 5
1 2 3 4
1 2 3 
1 2 
1 
```

### :warning: Забележки

- Давайте смислени имена на променливите си
- Целете се към максимално спазване на чист код 
- Винаги правете валидация на входните си данни
- Опитвайте се да отделяте логиката си в различни функции
- Винаги проверявайте дали успешно сте заделили памет и не допускайте **memory leaks**