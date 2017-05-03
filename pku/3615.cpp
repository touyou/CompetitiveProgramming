#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int INF=INT_MAX/2;
int n, m, t;
int d[300][300];
int main() {
    for (int i=0; i<300; i++) for (int j=0; j<300; j++) d[i][j]=INF;
    scanf("%d%d%d",&n,&m,&t);
    for (int i=0; i<m; i++) {
        int s, e, h; scanf("%d%d%d",&s,&e,&h);
        d[s-1][e-1]=h;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
        }
    }
    for (int i=0; i<t; i++) {
        int a,b;scanf("%d%d",&a,&b);
        if (d[a-1][b-1]==INF) puts("-1");
        else printf("%d\n",d[a-1][b-1]);
    }
}
