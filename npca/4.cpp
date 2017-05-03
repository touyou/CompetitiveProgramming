#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int fr[1000][1000];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) scanf("%d",&fr[j][i]);
    }
    int res=0;
    for (int i=0; i<m; i++) {
        int m=-10000;
        for (int j=0; j<n; j++) m=max(m, fr[i][j]);
        res+=m;
    }
    printf("%d\n",res);
}
