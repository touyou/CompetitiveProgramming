#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
struct elem {
    ll x, y;
};
int w, h, n;
elem e[100000];
ll x[100000], y[100000];
ll px[3], py[3];
int main() {
    scanf("%d%d%d",&w,&h,&n);
    for (int i=0; i<n; i++) {
        scanf("%lld%lld",&x[i],&y[i]);
        e[i]=(elem){x[i],y[i]};
    }
    sort(x, x+n);
    sort(y, y+n);
    px[0]=x[(n-1)/2];
    px[1]=x[(n+1)/2];
    py[0]=y[(n-1)/2];
    py[1]=y[(n+1)/2];
    ll res=LLONG_MAX, rx=0, ry=0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            ll calc=0, m=0;
            for (int k=0; k<n; k++) {
                ll temp=(abs(px[i]-e[k].x)+abs(py[j]-e[k].y));
                m=max(m, temp);
                calc+=temp;
            }
            if (res>calc*2-m) {
                res=calc*2-m;
                rx=px[i]; ry=py[j];
            }
        }
    }
    printf("%lld\n%lld %lld\n",res,rx,ry);
}
