#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
int field[1005][1005];
ll sum[1005][1005];
int m,n,a,b;
int main() {
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        scanf("%d",&field[i][j]);
        if (field[i][j]==-1) field[i][j]=INT_MAX;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            sum[i][j]=field[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    ll res=INT_MAX;
    for (int i=b; i<=n; i++) {
        for (int j=a; j<=m; j++) {
            ll s=sum[i][j]-sum[i-b][j]-sum[i][j-a]+sum[i-b][j-a];
            res=min(res, s);
        }
    }
    printf("%lld\n",res);
}
