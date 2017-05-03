#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t, x, y;
int s[1000][100];
int w[1000][100];
int res[1000];
int p[100];
int main() {
    scanf("%d%d%d%d%d",&n,&m,&t,&x,&y);
    for (int i=0; i<m; i++) scanf("%d",&p[i]);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        s[i][j]=-1;
    }
    for (int i=0; i<y; i++) {
        int tk,nk,mk; string stat;
        scanf("%d%d%d",&tk,&nk,&mk); nk--; mk--;
        cin>>stat;
        if (stat=="open") {
            s[nk][mk]=tk;
        }
        if (stat=="incorrect") {
            w[nk][mk]++;
        }
        if (stat=="correct") {
            res[nk]+=max(x,p[mk]-(tk-s[nk][mk])-120*w[nk][mk]);
        }
    }
    for (int i=0; i<n; i++) printf("%d\n",res[i]);
}
