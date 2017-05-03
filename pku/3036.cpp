#include <cstdio>
int dx[]={-1,0,-1,1,0,1};
int dy[]={-1,-1,0,0,1,1};
int memo[15][15][15];
int dfs(int x, int y, int cnt) {
    if (x==7&&y==7&&cnt==0) return 1;
    else if (cnt==0) return 0;
    if (memo[x][y][cnt]!=-1) return memo[x][y][cnt];
    int res=0;
    for (int i=0; i<6; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx>=0&&nx<=14&&ny>=0&&ny<=14) {
            res += dfs(nx,ny,cnt-1);
        }
    }
    return memo[x][y][cnt]=res;
}
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int n; scanf("%d",&n);
        for (int i=0; i<15; i++) for (int j=0; j<15; j++) for (int k=0; k<15; k++) {
            memo[i][j][k]=-1;
        }
        printf("%d\n",dfs(7,7,n));
    }
}
