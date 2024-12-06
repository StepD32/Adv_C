/*
На стандартном потоке ввода задаётся натуральное число N (N > 0),
после которого следует последовательность из N целых чисел.
На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум. 
Указание: использовать массивы запрещается. 

Входные данные
6 1 2 3 2 0 3

Результат работы
2

Входные данные
3 5 2 -1

Результат работы
1


*/
#include <stdio.h>
#include <inttypes.h>


void InputGet() {
    int number;   
    int max ;
    int currentNumber=0;
    int maxCount = 0;
        
    scanf("%d", &number);

    while(number>0){
        scanf("%d", &currentNumber);       
        if (maxCount == 0 || currentNumber > max) {
            max = currentNumber;
            maxCount = 1; 
        } else if (currentNumber == max) maxCount++; 
       number--;    
    }
    printf("%d\n", maxCount);
}

int main()
{
    InputGet();
	return 0;
}

