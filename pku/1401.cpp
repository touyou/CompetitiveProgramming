#include <cstdio>
typedef long long ll;
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        ll n; scanf("%lld",&n);
        ll five=5;
        ll res=0;
        while (five<=n) {
            res+=n/five;
            five*=5;
        }
        printf("%lld\n",res);
    }
}