#include <stdio.h>
typedef struct node
{
    int min,max;
}node;
node MinMax(int *arr, int low, int high)
{
    if( high - low == 1)
        return (node){.min = arr[low], .max = arr[low]};
    else if( high - low ==  2)
    {
        node t ;
        t.min = (arr[low] < arr[high-1] ? arr[low] : arr[high-1]);
        t.max = (arr[low] > arr[high-1] ? arr[low] : arr[high-1]);
        return t;
    }
    else
    {
        int mid = low + high >> 1;
        node a = MinMax(arr, low, mid);
        node b = MinMax(arr, mid, high), c;
        c.min = a.min < b.min ? a.min : b.min;
        c.max = a.max > b.max ? a.max : b.max;
        return c;
    }    
}    
void input(int *arr, int n)
{
    if(n > 1)
        input(arr, n - 1);
    scanf("%i",&arr[ n - 1]);

}    
int main()
{
    int n;
    scanf("%i",&n);
    int arr[n];
    input(arr,n);
    node ans = MinMax(arr,0,n);
    printf("\nMin : %i and Max : %i\n",ans.min,ans.max);

    return 0;
}
