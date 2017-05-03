#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int res, rcnt;
int gx, gy;
int map[10][10];
bool used[10][10];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool isin(int x, int y) {
    return x>=0&&y>=0&&x<m&&y<n;
}
void dfs(int x, int y, int c) {
    if (rcnt==c) {
        if (gx!=x&&gy!=y) return;
        if (gx==x) {
            for (int i=min(gy,y); i<=max(gy,y); i++) {
                if (i!=y&&map[x][i]==1) return;
            }
            res++;
        } else if (gy==y) {
            for (int i=min(gx,x); i<=max(gx,x); i++) {
                if (i!=x&&map[i][y]==1) return;
            }
            res++;
        }
        return;
    }
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        while (isin(nx,ny)&&(!used[nx][ny]||(used[nx][ny]&&map[nx][ny]!=1))) {
            // printf("%d %d %d\n",nx,ny,map[nx][ny]);
            if (map[nx][ny]==1) {
                used[nx][ny]=true;
                dfs(nx,ny,c+1);
                used[nx][ny]=false;
            }
            nx+=dx[i]; ny+=dy[i];
        }
    }
}
int main() {
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        res=0; rcnt=0;
        memset(used, 0, sizeof(used));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d",&map[i][j]);
                if (map[i][j]==2) {
                    gx=i; gy=j;
                    used[i][j]=true;
                } else if (map[i][j]==0) {
                    used[i][j]=true;
                } else {
                    rcnt++;
                }
            }
        }
        dfs(gx,gy,0);
        printf("%d\n",res);
    }
}
