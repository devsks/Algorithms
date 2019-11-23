#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
int main(){
    ll t;
    scanf("%lli", &t);
    while(t--){
        ll n, ans , sq;
        
        scanf("%lli", &n);
        ans = n;
        for(ll i = 2; i*i <= n; i++){
            if( (n % i) == 0){
                ans -= ans/i;
            }
            while( (n%i)==0)
                n/=i;
        }
        if(n > 1)
            ans -=ans/n ;
        printf("%lli\n", ans);

    }
    return 0;
}
