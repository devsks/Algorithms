/*
 * @brief Shell Sort.
 * @author devsks.
 * @quote "Code Like There's No Tommorow"
 * */
#include <stdio.h>
void shellsort(int*, int);
int main()
{
    int arr[] = {1, 2, 7, 69, 12, 5, 41};
    int n = sizeof(arr) / sizeof(int);
    shellsort(arr, n);
    for(int i = 0; i < n ;i++)
        printf("%i ", arr[i]);
    return 0;
}    
void shellsort(int *arr, int n)
{
    for(int gap = n >> 1; gap ; gap >>=1)
        for(int i = gap; i < n ; i += gap)
        {
            int key = arr[i], j = i - gap;
            for(  ;j >= 0 && key < arr[j] ; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = key;
        }    
}   
