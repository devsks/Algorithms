/*
 * brief@ KnapSack Fractional Problem.
 * author@ devsks
 * quote@ "Code Like There's No Tommorow!"
 */
#include <stdio.h>
#include <stdlib.h>
   
typedef struct node
{
    int wgt, val, ind;
    double dns;
}gold;

int cmp(const void *a, const void *b)
{
    return ( ((gold*)b)->dns  - ((gold*)a)->dns );
}

int main()
{
    int n, wMax, curW = 0, w;
    double profit = 0;

    printf("Enter the Number of items : ");
    scanf("%i", &n);
    
    gold jwel[n];
    
    printf("\nEnter the weight and value of items");
    for(int i = 0; i < n; i++)
    {
        scanf("%i %i", &jwel[i].wgt, &jwel[i].val);
        jwel[i].ind = i + 1;
        jwel[i].dns = (double)jwel[i].val / jwel[i].wgt;
    }    
    
    printf("\nEnter the capacity of the knapsack :");
    scanf("%i", &wMax);

    qsort(jwel, n, sizeof(gold), cmp);
    for(int i = 0; curW < wMax;i++)
    {
    
        if( curW + jwel[i].wgt <= wMax)
            w = jwel[i].wgt;
        else
            w = wMax - curW;
        curW += w;
        profit += jwel[i].dns * w;
        printf("\nItem %i is taken :", jwel[i].ind);
    }    
    printf("\nProfit : %lf", profit);
    return 0;
}
