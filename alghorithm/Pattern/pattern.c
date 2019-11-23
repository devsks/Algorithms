/*
 *
 * 1*2*3*4
 * 9*10*11*12
 * 13*14*15*16
 * 5*6*7*8
 */
#include <stdio.h>
#define FOR(X,Y) for(int X = 1; X <= Y; X++)
void print(int num,int n)
{
    FOR(j,n)
    {
        printf(" %2i ", num++);
        if( n - j > 0)
            putchar('*');
    } 

}    
int main()
{
    int n, num = 1, mul;
    scanf("%i", &n);

    FOR(i, n>>1)
    {
        print(num, n);
        num = (n<<1)*i + 1;
        puts("");
    }
    mul = n - 1;
    
    if(n&1)
    {    
        num = n * mul + 1;
        print(num, n);
        mul--;
        puts("");
    }

    FOR(i, n>>1)
    {   
        num = n * mul + 1;
        print(num, n);
        mul -= 2;
        puts("");
    }    
    return 0;
}    
