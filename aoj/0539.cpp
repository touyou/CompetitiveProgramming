#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll d;
    while (scanf("%lld",&d)) {
        if (!d) break;
        int n, m;
        scanf("%d%d",&n,&m);
        ll store[n+1], k;
        store[0]=0;
        for (int i=1; i<n; i++) scanf("%lld",&store[i]);
        sort(store, store+n);
        store[n]=d;
        ll res=0;
        for (int i=0; i<m; i++) {
            scanf("%lld",&k);
            int pos=upper_bound(store, store+n, k)-store;
            res+=min(store[pos]-k, k-store[pos-1]);
        }
        printf("%lld\n",res);
    }
}
