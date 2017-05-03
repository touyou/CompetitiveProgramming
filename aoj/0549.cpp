#include <cstdio>
#include <algorithm>
#define MOD 100000
using namespace std;
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int yado[n];
    yado[0]=0;
    scanf("%d",&yado[1]);
    for (int i=2; i<n; i++) {
        scanf("%d",&yado[i]);
        yado[i]+=yado[i-1];
    }
    int npos=0, in, res=0;
    for (int i=0; i<m; i++) {
        scanf("%d",&in);
        int s=npos, e=npos+in;
        npos=e;
        if (s>e) swap(s, e);
        // printf("%d %d\n",s,e);
        res += yado[e]-yado[s];
        res %= MOD;
    }
    printf("%d\n",res);
}
