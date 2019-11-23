#include <stdio.h>

int bsearch(int key, int * arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low+high) >> 1;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return bsearch(key, arr, low, mid);
        else
            return bsearch(key, arr, mid+1 , high);
    }
    else
        return -1;
}    
void input(int *arr, int n)
{
    if(n > 1)
        input(arr, n - 1);
    scanf("%i",arr + n - 1);

}    
int main()
{
    int n, key;
    scanf("%i",&n);
    int arr[n];
    input(arr, n);
    input(&key, 1);
    int ans = bsearch(key, arr, 0, n);
    printf("\nElement %i at %i\n",key,ans);

    return 0;
}
