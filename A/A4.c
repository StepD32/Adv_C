/*

На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным.
Программа должна вывести полученное число. 

Входные данные
2 1
Результат работы
1

Входные данные
12 3
Результат работы
6

Входные данные
3 5
Результат работы
3

Входные данные
1024 3
Результат работы
4

*/

#include <stdio.h>
#include <inttypes.h>

uint32_t N;
uint32_t K; 
uint32_t mask=0; 
uint32_t max = 0;

int main()
{

    int count = 0;
    int temp =0;
    
    scanf("%u %u", &N, &K);
    mask = (1 << K) - 1;
    while(count < 32){
        temp = (N >> count) & mask;  
        if (temp > max) max = temp;  
        count++;               
    }
    printf("%u\n",max);
    return 0;
}

