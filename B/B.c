/*
Описана структура данных 

typedef struct list
{
  uint64_t address; 
  size_t size; 
  char comment[64]; 
  struct list *next; 
} list; 

Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. 
Если список пустой, то функция должна возвращать NULL. 
Если есть несколько таких блоков, то вернуть адрес любого из них. 
Прототип функции: uint64_t findMaxBlock(list *head) 


Описана структура данных для хранения информации об использованной памяти: 
typedef struct list
{
 void *address; 
 size_t size; 
 char comment[64]; 
 struct list *next; 
}list; 

Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. 
Если список пустой, то функция должна возвращать NULL. 
Прототип функции: 
size_t totalMemoryUsage(list *head) 

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct list
{  
  uint64_t address; 
  size_t size; 
  char comment[64]; 
  struct list *next; 
} list; 


uint64_t findMaxBlock(list *head){
    uint64_t oldaddr = head->address;
    size_t oldsize =head->size;
        
    while (head != NULL){        
        if(head->size > oldsize ){
            oldsize = head->size;
            oldaddr = head->address;
        }
        head = head->next;
    }
    return oldaddr;

} 


size_t totalMemoryUsage(list *head){
    size_t oldsize = 0;    
    while (head != NULL){        
        oldsize+= head->size;
        head = head->next;
    }
    return oldsize;
} 

list* addBlockList(uint64_t addressNew, size_t sizeNew)
{    
    list* pListNext = (list*)malloc(sizeof(list));      
    pListNext->address = addressNew;
    pListNext->size = sizeNew;  
    pListNext->next = NULL;  
    return pListNext;    
} 

void printList(list *pList)
{   
    while(pList != NULL){
         printf("address = %I64d size = %d\n", pList->address, pList->size);  
         pList = pList->next;
    } 
} 

int main(int argc, char **argv){
    
    uint64_t num_adr = rand();        
    list *List;
    
    for(int i = 0; i<10; i++){
        size_t num_size = (rand()%100);
        List = addBlockList(num_adr+i, num_size);     
    }
    
    printList(List);
    printf("max %I64d\n",findMaxBlock(List));
}
