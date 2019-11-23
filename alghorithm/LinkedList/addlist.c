#include "list.h"
#include <stdbool.h>
int cmp(void* a, void*b)
{
	return ( *(int*)a-*(int*)b);
}
list* ispali(list * first, list * second,int(*cmp)(void*a,void*b))
{
	list * ptr = NULL;
	if (second->next && second->next->next)
	{	
		ptr = ispali(first->next, second->next->next, cmp);
	}
	else
	{
		ptr = first->next->next;
		if(second->next)
			first = first -> next;
		
	}
	if (ptr && printf("\nComparing %i with %i: \n", *(int*)first->n, *(int*)ptr->n) &&!cmp(first->n, ptr->n))
	{
			return ptr->next ? ptr->next : ptr;
	}
	return NULL;
}
int checkPali(list *arr, int(*cmp)(void*a,void*b))
{
	if(arr && arr->next && arr->next->next)
	{
		list *ptr  = ispali(arr, arr->next->next, cmp);
		
		if(ptr && !cmp(arr->n, ptr->n) )
			return ptr;
		else
			return NULL;
	}
	else if(arr && arr->next)
	{
		puts("sasa");
		if(cmp(arr->n, arr->next->n)==0)
			return arr;
		else
			return NULL;
	}
	return arr;
	
}
list *add(list *a, list *b)
{
    int carry = 0, pos=0;
    list *c = NULL;
    while(a || b)
    {
		int* value = (int*)calloc(1, sizeof(int) ); 
        if(a && b)
        {
            *value = (*(int*)a->n + *(int*)b->n + carry)%10;
            carry = (*(int*)a->n + *(int*)b->n +carry) / 10;
        }
        else if(b)
            *value = *(int*)b->n;
        else
            *value = *(int*)a->n; 
		a = a ? a->next : a;
		b = b ? b->next : b; 
		insert(&c,value,pos);
        ++pos;
    }
    return c;
}
list* addBack(list *a, list *b)
{
    if(!a && !b)
        return NULL;
    int* value = (int*)calloc(1, sizeof(int) ), carry,x=0,y=0;
    list *arr = (list*)calloc(1, sizeof(list)), *ptr = addBack(a ? a->next : a, b ? b->next : b);
	if(a && b)
    {
        x = *(int*)a->n;
        y = *(int*)b->n;
    }
    else if(a)
    	x = *(int*)a->n;
    else
        y = *(int*)b->n;
    
    carry = ptr ? (*(int*)ptr->n) / 10 : 0;
    if(ptr)
            *(int*)ptr->n = (*(int*)ptr->n) % 10;

     *value =  x + y + carry;       
     arr->n = value;
     arr->next = ptr;
     return arr;
}
list *addWa(list *a, list *b)
{
    list * c = addBack(a,b);
    //adding extra node in the front of the list, in case of a carry is generated
    if(*(int*)c->n > 9)
    {
        int* value = (int*)calloc(1, sizeof(int) );
        list *arr = (list*)calloc(1, sizeof(list));
        *value = *(int*) c->n / 10;
        *(int*)c->n = (*(int*)c->n)%10;
        arr->n = value;
        arr->next = c;
        c = arr;   
    }
    return c;
}
void print(list *begin, list *end)
{
    if(begin != end)
        printf("%5i ",*(int*) begin->n), print(begin->next, end);
} 
int main(void)
{
    list *a = NULL, *b=NULL, *c;
    int *arr[] = {6,1,1,6,2,9};
    
    insert(&a,arr+3,0);
    insert(&a,arr+2,0);
    insert(&a,arr+1,0);
    insert(&a,arr+0,0);
    
   // insert(&b,arr+6,0);
    insert(&b,arr+5,0);
    insert(&b,arr+4,0);
    insert(&b,arr+3,0);
    print(a,NULL);
    puts("");
    print(b,NULL);
    //c = addWa(a,b);
     puts("");
    print(c,0);
//    clean(c);
   // clean(b); clean(a);
  	printf("\nIs pali %i", checkPali(a,cmp));
	puts("");
    return 0;
}
