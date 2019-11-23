#include <stdio.h>
void heapSort(int*, int);
void heapify(int*, int ,int);
void swap(int *a, int*b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}    
int main()
{
    int arr[] = {79, 61, 120, 1, 23, 17, 55};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    return 0;
}

void heapSort(int* arr, int n)
{
    // Creating a max Heap
    for(int i = (n>>1)-1 ; i >= 0; i--)
        heapify(arr, i, n);
    // Sorting the array
    while(--n) 
        swap(arr, arr + n), heapify(arr, 0, n); 

}    
void heapify(int *arr, int paren, int n)
{
    if(paren < n >> 1)
    {
         int l = paren << 1 | 1;
         int r = l + 1;
         int max = r < n ? ( arr[l] > arr[r] ? l : r ) : l;
        if (arr[paren] < arr[max] ) 
            swap(arr + paren, arr + max), heapify(arr, max, n);
        
    }    


}   
