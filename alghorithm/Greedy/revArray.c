#include <stdio.h>
void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}   
void reverseK(int *arr, int n, int k)
{
    for(int i = 0; i < n; i += k)
    {
        int left = i, right =( i + k > n ? n : i + k);
        while(left < right)
            swap(arr + left++, arr+--right);    
    }
}    
int main()
{
    int n, k, tmp;
    scanf("%i",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%i", &arr[i]);    
    scanf("%i", &k);
    reverseK(arr, n, k);
    for(int i = 0 ; i < n; i++)
        printf("%i ",arr[i]);
    return 0;
}    
