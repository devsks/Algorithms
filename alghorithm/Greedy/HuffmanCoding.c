/*
 * @brief Huffman Coding Implementation using min Heap and Binary Tree.
 * @author devsks.
 * @quote "Code Like There's No Tommorow"
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
typedef struct node
{
        int fq;
        char ch;
        char bit[26];
        struct node * left;
        struct node * right;
}node;

node *heap[27], *arr[27];
char bitRep[27];

node* getNode(int fq,int c)
{
    node *in = (node *)calloc(1, sizeof(node));
    in->fq = fq;
    in->ch = (c == 26 ? '_' : 'a' + c) ;
    return in;
}    

void heapInsert(node *ptr, int ind)
{
    if(ind)
    {
        int p = (ind - 1) >> 1;
        while( p >= 0 && ind > 0 && heap[p]->fq > ptr->fq)
        {
            heap[ind] = heap[p];
            ind = p--;
            p >>= 1;
        }    
    }    
    heap[ind] = ptr;
}    
node* deleteHeap(int* heapSize)
{
    node *ins = heap[0];
    heap[0] = heap[--(*heapSize)];
    int l = 1, p = 0 , r = 2, ind;
    while (r < *heapSize || l < *heapSize)
    {
        if (l < *heapSize && r < *heapSize)
            ind = (heap[l]->fq < heap[r]->fq ? l : r);
        else 
            ind = l ;
        if (heap[p]->fq > heap[ind]->fq)
        {
            node *tmp = heap[p];
            heap[p] = heap[ind];
            heap[ind] = tmp;
        }    
        p = ind;
        l = p << 1 | 1;
        r = l + 1;
    } 
    return ins;
}    
void setBit(node *root, int ind)
{
    if(root->left)
    {    
        bitRep[ind] = '0';
        setBit(root->left, ind + 1);
    }
    if (root->right)
    {
        bitRep[ind] = '1';
        setBit(root->right, ind + 1);
    }    
    
    if (!root->left && !root->right)
    {
        bitRep[ind] = '\0';
        strcpy(root->bit, bitRep);
    }   
}    
int main()
{
    char msg[size];
    int fq[27] = {0}, len, index = 0, heapSize;
    // Message Input
    fgets(msg,size,stdin);
    len = strlen(msg);
    
    for(int i = 0; i < len; i++ )
            fq[ (msg[i] == ' ') ? 26 : msg[i]-'a']++;
        
    for(int i = 0; i <= 26; i++)
        if(fq[i])
        {
            arr[index] = getNode(fq[i], i);
            heapInsert(arr[index], index);
            index++;
        }

    heapSize = index;
    for(int i = 0; i < heapSize; i++)
         printf("%i %c\n",arr[i]->fq, arr[i]->ch);
    
    while(heapSize>1)
    {
        node *a = deleteHeap(&heapSize);
        node *b = deleteHeap(&heapSize);
        node *c = (node*)calloc(1, sizeof(node));
        c->fq = (a->fq + b->fq);
        c->left = a;
        c->right = b;
        heapInsert(c, heapSize++);
    }               
    puts("Encrypted Table :");
    setBit(heap[0], 0);
    for(int i = 0; i < index; i++)
         printf("%c %s\n",arr[i]->ch,arr[i]->bit);

    return  0;
}    
