#include <cstdio>
#include <algorithm>
using namespace std;
int w, h, sx, sy, gx, gy;
int board[20][20];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool isin(int x, int y) { return x>=0&&x<h&&y>=0&&y<w; }
int dfs(int x, int y, int cnt) {
    if (cnt==10) return 11;
    int res=11;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (!isin(nx,ny)) continue;
        if (isin(nx,ny)&&nx==gx&&ny==gy) return cnt+1;
        if (isin(nx,ny)&&board[nx][ny]==1) continue;
        while (isin(nx+dx[i],ny+dy[i])) {
            nx+=dx[i]; ny+=dy[i];
            if (!isin(nx,ny)) break;
            if (isin(nx,ny)&&nx==gx&&ny==gy) return cnt+1;
            if (isin(nx,ny)&&board[nx][ny]==1) {
                board[nx][ny]=0;
                res=min(res,dfs(nx-dx[i],ny-dy[i],cnt+1));
                board[nx][ny]=1;
                break;
            }
        }
    }
    return res;
}
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            scanf("%d",&board[i][j]);
            if (board[i][j]==2) {
                board[i][j]=0;
                sx=i; sy=j;
            }
            if (board[i][j]==3) {
                board[i][j]=0;
                gx=i; gy=j;
            }
        }
        int ans=dfs(sx,sy,0);
        printf("%d\n",ans==11?-1:ans);
    }
}
