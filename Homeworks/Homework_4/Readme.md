# Домашна работа 4 

## 1 зад. 
Напишете програма, която по въведена таблица от букви и речник с думи проверява за всяка 
дума дали е изпълнено точно едно от следните две условия. 
1) Думите, които се съдържат в таблицата и са съставени от букви над главния диагонал (без него),
се срещат и съставени от букви под главния диагонал (без него);
2) Ако дума, която се среща в таблицата съдържа букви от главния диагонал, то не трябва да се
среща съставена само от букви под или над него.

Дума може да се образува от последователни букви по: 
- хоризонтала – наляво или надясно
- вертикала – нагоре или надолу

**Вход:**
На първия ред на стандартния вход се въвеждат две цели числа 3 < N <= M < 100 - размерът на 
таблицата с букви. На втори ред се въвежда едно цяло число К - броят на думите в речника. След 
това се попълва таблицата само с малки букви; следват К на брой думи.

**Изход:**
За всяка дума да се изведе на отделен ред “YES”, ако изпълнява условието и “NO” в противен 
случай.

**Пример:**
```
4 4 
5 
g f m i 
f o g p 
m g a t 
i o l l 

fmi 
YES
goal 
NO
go 
NO
izpit 
NO
al 
YES
```

## 2 зад. 
Напишете функция char * stringReplace(const char * str, const char * what, const char * with),
която заменя всяко срещане на what в str с with. Резултатният стринг трябва да е с точната 
дължина.

## 3 зад. 
Напишете функция void reverseWords(char* str). Която обръща на обратно всяка 
валидна дума в str. Валидна дума наричаме всяка последователност от малки и големи 
латински букви, като между тях може да има тирета.
```
Вход:                                          Изход: 
Ima6е kozel v zadniq dvor na Ivan.             amI6е lezok v qindaz rovd an navI.
-Da - kaza Ivan-Aleksandur.                    -aD - azak rudnaskelA-navI.
```
