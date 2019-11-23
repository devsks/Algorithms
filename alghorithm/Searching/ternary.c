#include <stdio.h>
int search(int*arr, int low, int high, int key)
{
    if(low <= high)
    {
        int mid1 = ((low << 1) + high) / 3;
        int mid2 = (low + (high << 1)) / 3;
        if(arr[mid1] == key)
            return mid1;
        else if(arr[mid2] == key)
            return mid2;
        else if(key < arr[mid1])
            return search(arr, low, mid1 - 1, key);
        else if(key > arr[mid2])
            return search(arr, mid2 + 1, high, key);
        else
            return search(arr, mid1 + 1 , mid2 - 1, key);
    }    
    else
        return -1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int i = search(arr, 0, n - 1, 9);
    printf("\n2 is found at %i\n", i);
    return 0;
}
