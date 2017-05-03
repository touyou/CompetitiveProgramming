#include <cstdio>
#include <algorithm>
using namespace std;
int tri[5002][5002];
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int x, y, r; scanf("%d%d%d",&x,&y,&r);
        tri[x-1][y-1]=max(tri[x-1][y-1],r+1);
    }
    for (int i=1; i<n; i++) {
        tri[i][0]=max(tri[i-1][0]-1, tri[i][0]);
        tri[i][i]=max(tri[i-1][i-1]-1,tri[i][i]);
        for (int j=1; j<i; j++) {
            tri[i][j]=max(tri[i][j], max(tri[i-1][j-1],tri[i-1][j])-1);
        }
    }
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (tri[i][j]!=0) res++;
        }
    }
    printf("%d\n",res);
}
