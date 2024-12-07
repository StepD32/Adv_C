/*
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число. 

Входные данные
2 1
Результат работы
1

Входные данные
1 2
Результат работы
1073741824

Входные данные
3 1
Результат работы
2147483649

Входные данные
12 2
Результат работы
3

Входные данные
19 3
Результат работы
1610612738

*/

#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t number;
    uint32_t K;         
    scanf("%u %u", &number, &K);
    while(K){
        if((number&1)){
            number >>= 1;
            number |= 2147483648;
        }else{
            number >>= 1;
        }
        K--;
    }
    printf("%u",number);
    
	return 0;
}