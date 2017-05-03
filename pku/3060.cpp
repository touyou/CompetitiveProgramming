#include <cstdio>
#include <cstring>
#include <algorithm>
#define ma 1000000000
using namespace std;
typedef long long ll;
int t, d, n;
int x[100000], y[100000], cnt[2][1000], cnt2[1000][1000];
ll mods(ll n, int d) {
    if (n<0&&n%d!=0) {
        ll q=n/d; q--;
        n = n - q * d;
    } else {
        n %= d;
    }
    return n;
}
int main() {
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d%d",&d,&n);
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for (int i=0; i<n; i++) {
            ll xi,yi; scanf("%lld%lld",&xi,&yi);
            xi=mods(xi,d); yi=mods(yi,d);
            x[i]=xi; y[i]=yi;
            //printf("%lld %lld %d %d\n",xi,yi,x[i],y[i]);
            cnt[0][xi]++; cnt[1][yi]++;
            cnt2[xi][yi]++;
        }
        ll res=ma;
        for (int i=0; i<d; i++) {
            for (int j=0; j<d; j++) {
                ll temp=cnt[0][i]+cnt[1][j]-cnt2[i][j];
                //printf("%d %d %lld\n",i,j,temp);
                res=min(res,temp);
            }
        }
        printf("%lld\n",res);
    }
}
