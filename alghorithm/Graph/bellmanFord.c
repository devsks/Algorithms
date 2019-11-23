#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct node{
    int dist, p;
}node;
typedef struct edge{
    int u, v, d;
}edge;
void bellman_ford(node*, int, int, int, edge *);
void relax(node*, int, int, int);
int main(){
    int n, e, u, v, d, s;
    scanf("%i %i", &n, &e);
    edge set[e];
    for(int i = 0; i < e ; i++)
        scanf("%i %i %i", &set[i].u, &set[i].v, &set[i].d);
    scanf("%i", &s);
    node g[n];
    bellman_ford(g, n, s, e, set);
    for(int i = 0; i < n; i++){
        printf("\n%i -> %i", i, g[i].dist);
    }
    return 0;
}
void relax(node *g, int u, int v, int dist){
    if( g[u].dist == INT_MAX)
        return;
    else if(g[v].dist > g[u].dist + dist){
        g[v].dist = g[u].dist + dist;
        g[v].p = u;
    }    

}
void bellman_ford(node *g, int n, int s, int e, edge *w){
    /* Initialization*/
    for(int i = 0; i < n; i++){
        g[i].dist = i == s ? 0 : INT_MAX;
        g[i].p = -1;
    }
    for(int k = 1; k < n; k++)
        for(int i = 0; i < e; i++)
            relax(g, w[i].u, w[i].v, w[i].d);

}
