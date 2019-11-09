#include <cstdio>
typedef long long ll;
int main() {
    ll gcd, lcm;
    scanf("%lld%lld",&gcd,&lcm);
    ll div=lcm/gcd,a,b;
    for (ll i=1; i*i<div; i++) {
        if (div%i==0) {
            b=div/i;
            a=i;
        }
    }
    printf("%lld %lld\n",a*gcd,b*gcd);
}
