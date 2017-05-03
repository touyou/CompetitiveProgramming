#include <cstdio>
typedef long long ll;
ll n, m;
int main() {
    scanf("%lld%lld",&n,&m);
    ll ret=0;
    for (ll i=1; i*i<=m; i++) {
        ret+=m/i*2-i*2+1;
        if (i*i<=n-1) ret-=(n-1)/i*2-i*2+1;
    }
    printf("%lld\n",ret);
}
