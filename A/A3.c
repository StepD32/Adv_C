/*
Извлечение бит
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется взять K младших битов числа N и вывести полученное таким образом число. 

Входные данные
2 1

Результат работы
0

Входные данные
12 3

Результат работы
4

Входные данные
3 5

Результат работы
3

Входные данные
1024 3

Результат работы
0
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t number;
uint32_t K; 
uint32_t mask=0; 

int main()
{
    scanf("%u %u", &number, &K);  
    int count = 0;
    while(count < K){
        mask = mask | (1<< count); 
        count++;        
    }
    printf("%d\n",number&mask);
    return 0;
}
