/*
 * brief@ Depth First Graph Traversal and Minimum Distance between Source and Destination node.
 * author@ devsks
 * quote@ "Code Like There's No Tommorow."
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y))
#define PAREN 1
#define DISTANCE 2
typedef struct node{
    int vertx;
    struct node *next;

}graph;
void insert(graph **root, int val)
{
    graph * tmp = (graph*) calloc(1,sizeof(graph));
    tmp->vertx = val;
    tmp->next = *root;
    *root = tmp;
}// end of insert()    

void DFS( graph **G, int root,int *paren, int *dist)
{
    int stack[123], top = -1, vis[123] = {0}, u, v;

    stack[++top] = root;
    vis[root] = 1;
    while(top >= 0 )
    {
        v = stack[top--];
        for(graph *p = G[v]; p!=NULL ; p = p->next)
        {
            u = p->vertx;
        
                if(!vis[u]++)
                {    
                    stack[++top] = u;
                    paren[u] = v ;
                    dist[u] = dist[ paren[u] ] + 1 ;
                }
        }   //end of for loop 
    }   //end of while loop 
}   // end of BFS()

int main()
{
    int nodes, edges, u, v, root;
    scanf("%i %i",&nodes, &edges);
    graph *G[nodes + 1];

    int dist[nodes+ 1], paren[nodes + 1];
    for(int  i= 1; i <= nodes; i++)
    {
        G[i] = NULL;
        dist[i] = i>>1 ? INT_MAX : 0;
        paren[i] = 0;
    }    
    while(edges--)
    {    
        scanf("%i %i", &u, &v);
        insert(&G[u], v);
        insert(&G[v], u);
    }
    scanf("%i", &root);    
    DFS(G, root, paren, dist);
    for(int i = 1; i <= nodes; i++)
        if(i !=root)
            printf("Node %2i : Parent = %2i Distance from root = %2i\n", i, paren[i], dist[i]);
    
    return 0;
}    
