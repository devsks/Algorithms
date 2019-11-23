#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct node{
    int u, v, wgt;
}node;

int cmp( const void *a, const void *b)
{
    node x = *(node*)a, y = *(node*)b;
    return x.wgt - y.wgt;
}
int checkloop(int, int, int*);
int root(int, int*);
void kruskal(node *, int, int);
int main()
{

    int n, e, u ,v, d, k = 0;
    scanf("%i %i", &n, &e);
    node g[e];
    for(int i = 0; i <e; i++)
    {
        scanf("%i %i %i", &u, &v, &d);
        g[i].u = u;
        g[i].v = v;
        g[i].wgt = d;
    }    
    qsort(g,e,sizeof(node), cmp);
    kruskal(g, n, e);
    return 0;

}    
void kruskal(node*g, int n, int e)
{
    int dset[n], min = 0;
    for(int i = 0; i < n; i++)
        dset[i] = i;

    for(int i = 0; i < e; i++)
    {
        int u = g[i].u;
        int v = g[i].v;
        if(checkloop(u, v, dset))
        {
            min += g[i].wgt;
            dset[v] = u;
        }
    }    
    for(int i = 0; i < n; i++)
        if(i - dset[i])
        {    
            printf("\nEdge between %c -> %c",i+'A', dset[i]+'A');
        }
    printf("\nMin value : %i", min); 
}
int checkloop(int u, int v, int* dset)
{
    return( root(u, dset) - root(v, dset) );
}    
int root(int u, int* dset)
{
    while(dset[u]!=u)
    {    
        u = dset[u] = dset[dset[u]];
    }
    return u;
}

