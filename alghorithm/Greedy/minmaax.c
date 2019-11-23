#include <stdio.h>
typedef struct node{
        int min,max;
}node;
node minmax(int*arr, int l, int r)
{
    if (r - l == 1)
        return (node){.min = arr[l],.max=arr[r - 1]};
    else if(r - l == 2)
    {
        node aux;
        aux.min = arr[l] < arr[r - 1] ? arr[l] : arr[r-1];
        aux.max = aux.min == arr[l] ? arr[r - 1] : arr[l];
        return aux;
    }   
    else
    {
        int mid = l+r >>1;
        node left = minmax(arr, l, mid);
        node right = minmax(arr, mid, r);
        node aux;
        aux.min = left.min < right.min ? left.min : right.min;
        aux.max = left.max > right.max ? left.max : right.max;
        return aux;
    }    
        


}    
int main()
{
    int arr[] = {34,1,79,15,4,55,420};
    int n = sizeof(arr)/sizeof(int);
    node aux = minmax(arr, 0, n);
    printf("MIN : %i\nMAX : %i\n",aux.min, aux.max);

}
