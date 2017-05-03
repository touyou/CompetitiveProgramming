#include <cstdio>
typedef long long ll;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
int main() {
    ll mx=0, bunbo=1;
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int o, y; scanf("%d%d",&o,&y);
        if (o==1) mx+=y*bunbo;
        if (o==2) mx-=y*bunbo;
        if (o==3) mx*=y;
        if (o==4) bunbo*=y;
        ll x=gcd(mx,bunbo);
        mx/=x;
        bunbo/=x;
    }
    printf("%lld\n",mx/bunbo);
}
