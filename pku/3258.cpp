#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int l, n, m;
ll x[50002];
bool C(int d) {
    int last=0;
    for (int i=1; i<n-m; i++) {
        int crt=last+1;
        while (crt<n&&x[crt]-x[last]<d) {
             crt++;
        }
        if (crt==n) return false;
        last=crt;
    }
    return true;
}
int main() {
    scanf("%d%d%d",&l,&n,&m);
    x[0]=0; x[n+1]=l;
    for (int i=1; i<=n; i++) scanf("%lld",&x[i]);
    n+=2;
    sort(x,x+n);
    ll lb=0, ub=l+1;
    while (ub-lb>1) {
        ll mid=(lb+ub)/2;
        if (C(mid)) lb=mid;
        else ub=mid;
    }
    printf("%lld\n",lb);
}
