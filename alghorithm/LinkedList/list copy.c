	
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "list.h"

/*
	Insert the node at the given position. I position is out of bound 
	then its add them to the end og the linked list.
*/
void insert(list **arr, void* n, int pos)
{
    list *tmp = (list*)calloc(1, sizeof(list)), *ptr, *prev = *arr;
	tmp->n = n;
	int i;
	for(i = 0, ptr = *arr; i < pos && ptr; ++i, prev = ptr, ptr = ptr->next);
	tmp->next = ptr;
	if(ptr == *arr)
		*arr = tmp;
	else
		prev->next = tmp;
}

list* findElement(list* ptr, int pos)
{
	if(pos==0)
		return 0;
	list *run = ptr;
	while(pos-- && run)
		run = run->next;

	if (pos + 1)
		return 0;
	while(run)
	{
		run = run->next;
		ptr = ptr->next;
	}
	return ptr;

}
list * reverse(list *arr)
{
	if(arr && arr->next)
	{
		list * ptr = reverse(arr->next);
		arr -> next -> next = arr;
		arr -> next = 0;
		return ptr;
	}		
	
	return arr;	
} 
/*
	It deallocates the allocated memory.
	By freeing the void pointer inside the structur and the structure itself.
*/
void clean(list *root)
{
	if(root)
	{
		clean(root->next);
		free(root->n);
		free(root);
	}
}
// MOST AWESOME INSERTION SORT <3 <3
void insertSort(list **root, int (*cmp)(void*, void*))
{
	list *arr = *root;
	if( arr && arr->next )
	{
		insertSort(&arr->next, cmp);
		list **prev = root, *next_ptr = arr->next;
		// Shigting nodes as needed
		while (next_ptr && cmp(next_ptr->n, arr->n) < 0)
		{
			*prev = next_ptr;
			prev = &( (*prev)->next);
			next_ptr = next_ptr->next;
		}
		*prev = arr;
		arr->next = next_ptr;
	}
}     
list* merge(list* a, list*b,int (*cmp)(void*, void*))
{
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    else
    {
        list *ptr;
        if( cmp(a->n,b->n) < 0)
        {
            ptr = a;
            ptr->next = merge(a->next, b, cmp);
        }    
        else
        {
            ptr = b;
            ptr->next = merge(a, b->next, cmp);
        }
        return ptr;
    }   
}   

void mergeSort(list **begin,int (*cmp)(void*, void*))
{
    if( *begin && (*begin)->next)
    {    
        // Partition Code Begins
        list *mid = *begin, *fast = *begin, *end;
        while(fast->next && fast->next->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }    
        end = mid->next;
        mid->next = NULL;
        //Partiton Code Complete66  
        mergeSort(begin, cmp);
        mergeSort(&end, cmp);
        *begin = merge(*begin, end, cmp);
    }
}
int delMiddle(list * ptr)
{
	if(ptr && ptr->next && ptr->next->next)
	{
		list* prev = NULL, *run = ptr;
		while( run->next && run->next->next)
		{
				prev = ptr;
				ptr = ptr->next;
				run = run->next->next;
		}
		prev ->next =  ptr->next;
		free(ptr->n);
		free(ptr);
		return 1;
	}

	return 0;
}

list* partition(list* ptr, void* a, int (*cmp)(void*, void*))
{
	list* left = NULL, *right = NULL;
	while(ptr)
	{
		if(cmp(a,ptr->n) > 0)
		{
			printf("%i < %i\n",*(int*) ptr->n, *(int*)a);
			if(!left)
				left = ptr;
			else{
				left->next = ptr;
				left = left->next;	
			}
		}
		else
		{
			if(!right)
				right = ptr;
			else
			{
				right->next = ptr;
				right = right->next;
			}
		}
		ptr = ptr->next;
	}
	if(left)
	{
		left->next = right;
		right->next = NULL;
		
	}
	if(right && !left)
	{
		right->next = NULL;
		return right;
	}
	return left;
}