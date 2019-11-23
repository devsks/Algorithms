/*
 * brief@ KnapSack 0-1 Problem using recurrsion.
 * author@ devsks
 * quote@ "Code Like There's No Tommorow!"
 */
#include <stdio.h>
#define size 20
#define max(X, Y) ( (X) > (Y) ? (X) : (Y) )
int fillSack(int n, int w, int *wgt, int *val)
{
    if(!n || !w)
        return 0;
    else if (wgt[n] > w)
        return fillSack(n - 1, w, wgt,val);
    else
        return max( fillSack(n - 1, w, wgt, val), val[n] + fillSack(n - 1, w - wgt[n], wgt,val));
    
}    
int main()
{
    int n, wMax, curW = 0, w;
    double profit = 0;
    int wgt[size], val[size];

    printf("Enter the Number of items : ");
    scanf("%i", &n);
    
    printf("\nEnter the weight and value of items");
    for(int i = 1; i <= n; i++)
        scanf("%i %i", &wgt[i], &val[i]);    
    
    printf("\nEnter the capacity of the knapsack :");
    scanf("%i", &wMax);

    int mat[n+1][wMax+1];   
    for(int i = 0 ; i <= n; i++)
        for(int j = 0; j <= wMax; j++)
            if(!j || !i)
                mat[i][j] = 0;
            else
                mat[i][j] = (wgt[i] > j) ? mat[i - 1][j] : max(mat[i - 1][j], val[i] + mat[i - 1][j - wgt[i]] );
                 
    
    printf("\nProfit : %i %i", mat[n][wMax], fillSack(n, wMax,wgt,val));
    return 0;
}
