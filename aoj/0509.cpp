#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, r, mx, Mx, my, My, res, a, b, c, d, i, j;
int mp[10003][10003];
int main() {
    while (scanf("%d%d",&n,&r)) {
        if (!n&&!r) break;
        memset(mp,0,sizeof(mp));
        mx=10003; Mx=0; my=10003; My=0;
        for (i=0; i<n; i++) {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a++; b++; c++; d++;
            mp[a][b]++; mp[c][d]++;
            mp[a][d]--; mp[c][b]--;
            mx=min(mx,a);
            Mx=max(Mx,c+1);
            my=min(my,b);
            My=max(My,d+1);
        }
        for (i=mx; i<Mx; i++) {
            for (j=my; j<My; j++) mp[i][j]+=mp[i][j-1];
        }
        res=0;
        for (i=my; i<My; i++) {
            for (j=mx; j<Mx; j++) {
                mp[j][i]+=mp[j-1][i];
                if (mp[j][i]!=0) res++;
            }
        }
        printf("%d\n",res);
        if (r==2) {
            res=0;
            for (i=mx; i<Mx; i++) for (j=my; j<My; j++) {
                if (mp[i][j]) res+=!mp[i-1][j]+!mp[i][j-1]+!mp[i+1][j]+!mp[i][j+1];
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
