#include <cstdio>
#include <algorithm>
using namespace std;
int m,n;
int mat[2000][2000];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int dfs(int x, int y) {
    mat[x][y]=0;
    int res=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx>=0&&nx<m&&ny>=0&&ny<n&&mat[nx][ny]==1) res+=dfs(nx,ny);
    }
    return res;
}
int main() {
    while (scanf("%d%d",&m,&n)!=EOF) {
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) scanf("%d",&mat[i][j]);
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j]==1) {
                    res=max(res,dfs(i,j));
                }
            }
        }
        printf("%d\n",res);
    }
}
