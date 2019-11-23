#include <stdio.h>
int gcdExtended(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0, *y = 1;
        return b;
    }
    else{
        int r, x1, y1;
        r = gcdExtended(b%a, a, &x1, &y1);
        printf("%i*%i + %i*%i = %i\n",b%a,x1,a,y1,r);
        *x = y1 - (b/a)*x1;
        *y = x1;
        return r;
    }

}
int main(){
    int a, b, x, y, m;
    scanf("%i %i",&a, &b);
    m = gcdExtended(a, b, &x, &y);
    printf("%i*%i + %i*%i = %i\n",a,x,b,y,m);
    return 0;
}
