/* 
 * Recursion DUDE !
 *	
 */
#include <stdio.h>
#define endl puts("")
void input(int n, int *arr)
{
	if (n > 1)
		input(n - 1, arr);
	scanf("%i", &arr[n - 1]);
}
void print(int n, int *arr)
{
	if(n>1)
		print(n - 1, arr);
		printf("%i ", arr[n - 1]);
}
void insert(int j, int *arr,int key)
{
	if ( j >= 0 && key < arr[j])
		arr[j + 1] = arr[j], insert(j - 1, arr, key);
	else
		arr[j + 1] = key;
}
void sort(int n, int *arr)
{
	if (n > 2)
        sort(n - 1, arr);
	insert(n - 2, arr, arr[n - 1]);

}
int main()
{
	int n, arr[100];

	scanf("%i",&n);
	input(n, arr);		
    endl;
	
	sort(n, arr);
	print(n, arr);			

	return 0;
}
