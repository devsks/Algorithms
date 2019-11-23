#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
typedef struct node list;
struct node
{
    void* n;
    list *next;
};

void insert(list **, void*, int );
list* findElement(list*, int);
list * reverse(list *);
	
void clean(list *);
// MOST AWESOME INSERTION SORT <3 <3
void insertSort(list **, int (*)(void*, void*));
list* merge(list* , list*, int (*)(void*, void*));

void mergeSort(list **, int (*)(void*, void*));
int delMiddle(list *);
list* partition(list*, void*, int (*)(void*, void*));
#endif