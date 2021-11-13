# Домашна работа 3 

## 1зад. 
Напишете програма, която чете от конзолата цяло положително число **n** (не по-голямо от 128) и след това създава матрица с размер **n x n** , която съдържа числата от **0** до
**$n^2$ − 1**. Обходете всички диагонали успоредни на главния диагонал, започвайки от долен 
ляв ъгъл и движещи се нагоре (когато се намирате в даден диагонал пробягвате 
стойностите отдолу нагоре). Изведете на екрана резултата от обхождането.
**Пример:**
```
Вход: 3          Вход: 4 
Изход:           Изход:
5 7 8            9 12 14 15
2 4 6            5 8  11 13
0 1 3            2 4  7  10
                 0 1  3  6
```
## 2зад. 
Напишете програма, която чете от конзолата цяло положително число **n** (не по-голямо от 500), след което потребителят въвежда **n** на брой чели числа (които по 
абсолютна стойност не надвишават 5000). Изведете на екрана най-често срещаното число, 
ако са няколко изведете само първото. 

## 3зад. 
Матрица **n** х **n+1** задава коефициентите пред променливите в система от линейни 
нехомогенни уравнения (в **n+1** – вия стълб са стойностите след знака за равенство). 
Напишете програма която решава системата, например по метода на Гаус, за n < 500. 