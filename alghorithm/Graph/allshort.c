#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MIN(X, Y) ( (X) < (Y) ? (X) : (Y))
void shortpath(int, int**, int**);
void printrow(int*a, int n)
{
        printf("  | ");
        for(int j = 0; j < n; j++)
            a[j] == INT_MAX ? printf("  N") : printf("%3i", a[j]);
        printf(" |");
}    
void print(int** boo, int n, int**bar)
{
    for(int i = 0; i < n; i++)
        puts(""), printrow(boo[i], n), printrow(bar[i], n);
}
void printpath(int, int, int**);
int main()
{
    int n, e, u ,v, dst;
    scanf("%i %i",&n,&e);
    int** d = (int**)calloc(n, sizeof(int*));
    int** p = (int**)calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++)
    {    
        d[i] = (int*)calloc(n,sizeof(int));
        p[i] = (int*)calloc(n,sizeof(int));
        p[i][i] = INT_MAX;
        for(int j = 0; j < n; j++)
            if(i != j)
                d[i][j] = p[i][j] = INT_MAX;
    }
    for(int i = 0; i < e; i++)
    {
        scanf("%i %i %i", &u, &v,&dst);
        d[u-1][v-1] = dst;
        p[u-1][v-1] = u ;
    }    
    shortpath(n,d,p);

    scanf("%i %i", &u, &v), printpath(--u, --v, p);
    return 0;
}    
void shortpath(int n, int **d, int **p)
{
    printf("\nk = %i\n", 0), print(d, n, p);
    for(int k = 0; k < n; k++)
    {    
        for(int i = 0; i < n;i++)
            for(int j = 0; j < n; j++)
                if(i != j)
                {
                    int aux  = d[i][j];
                    d[i][j] = (d[i][k] == INT_MAX || d[k][j] == INT_MAX ) ? d[i][j] : MIN(d[i][j], d[i][k] + d[k][j]);     
                    p[i][j] = aux != d[i][j] ? p[k][j] : p[i][j];
                }
        printf("\nk = %i\n", k + 1), print(d, n, p);
    }
}    
void printpath(int u, int v, int **p)
{
    if( p[u][v] - u != 1)
        printpath(u, p[u][v] - 1, p), printpath( p[u][v] -1, v, p);
    else
        printf("\n%i -> %i", u + 1, v + 1);
}    
