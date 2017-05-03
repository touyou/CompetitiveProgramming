#include <cstdio>
#include <climits>
#include <algorithm>
#define inf INT_MAX/2
using namespace std;
int d[1000];
int n,ml,md;
int al[10000], bl[10000], dl[10000];
int ad[10000], bd[10000], dd[10000];
int main() {
    scanf("%d%d%d",&n,&ml,&md);
    fill(d, d+n, inf);
    d[0]=0;
    for (int i=0; i<ml; i++) {
        scanf("%d%d%d",&al[i],&bl[i],&dl[i]);
    }
    for (int i=0; i<md; i++) {
        scanf("%d%d%d",&ad[i],&bd[i],&dd[i]);
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i+1<n; i++) {
            if (d[i+1]<inf) d[i]=min(d[i], d[i+1]);
        }
        for (int i=0; i<ml; i++) {
            if (d[al[i]-1]<inf) {
                d[bl[i]-1]=min(d[bl[i]-1],d[al[i]-1]+dl[i]);
            }
        }
        for (int i=0; i<md; i++) {
            if (d[bd[i]-1]<inf) {
                d[ad[i]-1]=min(d[ad[i]-1],d[bd[i]-1]-dd[i]);
            }
        }
    }
    int res=d[n-1];
    if (d[0]<0) {
        res=-1;
    } else if (res==inf) {
        res=-2;
    }
    printf("%d\n",res);
}
