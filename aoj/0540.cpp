#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct amida {
    int a, b;
};
bool comp(const amida& a, const amida& b) {
    return a.b<b.b;
}
int n, m, h, k;
int sc[1000], num[1000], res[1000];
amida ami[100000], scs[100000], ns[100000];
int main() {
    while (scanf("%d%d%d%d",&n,&m,&h,&k)) {
        if (!n&&!m&&!h&&!k) break;
        for (int i=0; i<n; i++) scanf("%d",&sc[i]);
        for (int i=0; i<m; i++) {
            scanf("%d%d",&ami[i].a,&ami[i].b);
        }
        sort(ami, ami+m, comp);
        for (int i=0; i<n; i++) num[i]=i;
        // number
        for (int i=0; i<m; i++) {
            ns[i].a=num[ami[i].a-1];
            ns[i].b=num[ami[i].a];
            swap(num[ami[i].a-1], num[ami[i].a]);
        }
        // score
        for (int i=m-1; i>=0; i--) {
            scs[i].a=sc[ami[i].a-1];
            scs[i].b=sc[ami[i].a];
            swap(sc[ami[i].a-1], sc[ami[i].a]);
        }
        // calc
        memset(res, 0, sizeof(res));
        int d=0;
        for (int i=0; i<m; i++) {
            res[ns[i].a]=scs[i].b;
            res[ns[i].b]=scs[i].a;
            if (0<=ns[i].a&&ns[i].a<k&&0<=ns[i].b&&ns[i].b<k) {
                continue;
            } else if (0<=ns[i].a&&ns[i].a<k) {
                d=min(d, scs[i].a-scs[i].b);
            } else if (0<=ns[i].b&&ns[i].b<k) {
                d=min(d, scs[i].b-scs[i].a);
            }
        }
        //printf("%d\n",d);
        ll ans=d;
        for (int i=0; i<k; i++) ans+=res[i];
        printf("%lld\n",ans);
    }
}