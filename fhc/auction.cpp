#include <cstdio>
typedef long long ll;
// Pi = ((A * Pi-1 + B) mod M) + 1
// Wi = ((C * Wi-1 + D) mod K) + 1
int main() {
    int t; scanf("%d",&t);
    ll n, p, w, m, k, a, b, c, d;
    for (int ix=1; ix<=t; ix++) {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",
            &n,&p,&w,&m,&k,&a,&b,&c,&d);
        
