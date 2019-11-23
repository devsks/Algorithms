#include <stdio.h>
#include "list.h"
/*
    Prints the elements in the linked list
*/
void print(list *begin, list *end)
{
    if(begin != end)
        printf("%i ",*(int*) begin->n), print(begin->next, end);
} 
/*
    Comparision function to help in osrting and searching
*/ 
int cmp(void *a, void *b)
{
    return (*(int*)a - *(int*)b);

}  
int main()
{
    int n, choice, position,*value;
    list *arr = NULL, *ptr;
    do
    {
        printf("Master Linked List : "), print(arr,NULL);
        puts("\n1.Add element."
			"\n2.Kth element."
			"\n3.Reverse  list."
        	"\n4.Sort list."
        	"\n5.Delete Middle"
            "\n6.Partition along X"
            "\n7.Exit.");
        
		scanf(" %i", &choice);

        system("clear");
        
        switch(choice)
        {    
            case 1:
                    puts("1.Enter the position : (0 for front and -1 for end).");  
                    scanf("%d", &position);
                    value = (int*) calloc(1, sizeof(int));
                    printf("\nEnter the number : "), scanf("%d", value);
                    insert(&arr, value, position);
                    break;
            case 2: printf("Enter the position : "), scanf("%i", &n);
                    ptr = findElement(arr, n);
                    if(ptr==NULL)
                        printf("Invalid Position");
                    else
                        printf("The value is : %i\n", *(int*) ptr->n);
                    break;
            case 3: arr = reverse(arr);
                    break;
            case 4: mergeSort(&arr, cmp);
                    break;
            case 5: if(!delMiddle(arr))   
                        printf("Cant delete the first and last node\n");
                    break;

            case 6: value = (int*) calloc(1, sizeof(int));
                    printf("Enter the value of x: "); scanf("%d", value);
                   arr = partition(arr, value, cmp);
                    break;
            case 7: clean(arr); return EXIT_SUCCESS;
            default : choice = 5, fflush(stdin), puts("Invalid Choice. Retry!");
        }           
    
    }while(EXIT_FAILURE);


    return EXIT_SUCCESS;
}    

