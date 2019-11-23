#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define FOR(X, Y) for(int X = 0; X < Y; X++)
#define MIN(X, Y) ( (X) < (Y) ? (X) : (Y))
typedef struct node{
    int vertex, dist;
}node;
int prims(int**, int, int);
int get_next_min(node*, int*, int);
void update_node(node*, int*, int, int);
int main()
{
    FILE* inptr = stdin;
    if( inptr)
    {
        int v, i , j, e, u, n, d, r;
        fscanf(inptr, "%i %i", &n, &e);
        int **cost = (int**)calloc(n, sizeof(int*));
        FOR(i,n)
        {    
            cost[i] = (int*)malloc(n * sizeof(n));
            FOR(j, n)
                cost[i][j] = i-j ? INT_MAX : 0;
        }

        FOR(i,e)
        {
            fscanf(inptr, "%i %i %i", &u, &v, &d);
            if(u == v)
                continue;
            // Minimum Parallel edge (If any)
            cost[u][v] = MIN(cost[u][v],d);
            cost[v][u] = MIN(cost[u][v],d);
        }    
        // source node
        fscanf(inptr, "%i", &r);
        int min_dist = prims(cost, r, n);
        printf("\nTotal Distance : %i\n", min_dist);
    }    
    else
        puts("Unable to read the input source");
    return 0;
}
int prims(int ** cost, int source, int v)
{
    int edgeSet[v], heapSize = v, map[v],dist = 0, k = 1, u;
    node heap[v];
    heap[0].vertex = source;
    map[source] = 0;

    FOR(i, v)
    {       
        edgeSet[i] = -1;
        heap[i].dist = INT_MAX;
        if(source - i)
        {    
            heap[k].vertex = i;
            map[i] = k++;
        }    
    }  
    while(heapSize--)
    {
        u = get_next_min(heap, map, heapSize);
        FOR(i, heapSize)    
            if(  cost[u][heap[i].vertex] < heap[i].dist)
            {
                edgeSet[heap[i].vertex] = u;
                update_node(heap, map, heap[i].vertex, cost[u][heap[i].vertex]);
            }  
    }
    FOR(i,v)
    {
        if(edgeSet[i] + 1)
        {
            printf("\n Edge between %c and %c", i + 'A', edgeSet[i] + 'A');
            dist += cost[i][edgeSet[i]];
        }    
    }    
    return dist;
}

int get_next_min(node *heap, int *map, int heapSize)
{
    int ret = heap[0].vertex, p = 0, l, r, min;
    heap[p] = heap[heapSize];
    map[heap[p].vertex] = p;
    while (p < heapSize >> 1 )
    {
         l = p << 1 |1;
         r = l + 1;
         min = r < heapSize ? (heap[l].dist < heap[r].dist ? l : r) : l;
        if( heap[p].dist > heap[min].dist)
        {
            map[heap[p].vertex] = min;
            map[heap[min].vertex] = p;
            
            node tmp =  heap[p] ;
            heap[p] = heap[min];
            heap[min] = tmp;
            p = min;
         }    
        else
            break;
    }    

    return ret;
}
void update_node(node *heap, int *map, int u, int val)
{
    int c = map[u], p;
    heap[c].dist = val;
    while(c)
    {
        p = c >> 1;
        if(heap[p].dist >  heap[c].dist)
        {
            map[heap[p].vertex] = c;
            map[heap[c].vertex] = p;
            node tmp =  heap[p] ;
            heap[p] = heap[c];
            heap[c] = tmp;
            c = p;
        }    
        else
            break;
    }    
    
}    

