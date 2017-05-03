#include <cstdio>
#include <cstring>
#define max(a,b) (a)>(b)?(a):(b)
int n, d, k;
int cow[1000][15];
bool ok[1000];
int main() {
    scanf("%d%d%d",&n,&d,&k);
    for (int i=0; i<n; i++) {
        int di; scanf("%d",&di);
        for (int j=0; j<di; j++) {
            int dis; scanf("%d",&dis);
            cow[i][dis-1]=1;
        }
    }
    int res=0;
    for (int i=0; i<(1<<d); i++) {
        if (__builtin_popcount(i)>k) continue;
        memset(ok, 0, sizeof(ok));
        for (int j=0; j<d; j++) {
            if ((i>>j)&1) continue;
            for (int k=0; k<n; k++) if (cow[k][j]) ok[k]=true;
        }
        int cnt=0;
        for (int j=0; j<n; j++) if (!ok[j]) cnt++;
        res=max(res,cnt);
    }
    printf("%d\n",res);
}