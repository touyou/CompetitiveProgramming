#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n, mat[105][105];
bool used[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool isin(int x, int y) { return x>=0&&x<n&&y>=0&&y<n; }

bool dfs(int x, int y, int lo, int up, int diff) {
    if (x==n-1&&y==n-1) return true;
    used[x][y]=true;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (isin(nx,ny)&&!used[nx][ny]) {
            int lt=min(lo, mat[nx][ny]);
            int ut=max(up, mat[nx][ny]);
            if (ut-lt<=diff&&dfs(nx,ny,lt,ut,diff)) {
                used[x][y]=false;
                return true;
            }
        }
    }
    used[x][y]=false;
    return false;
}

bool C(int diff) {
    memset(used, 0, sizeof(used));
    return dfs(0,0,mat[0][0],mat[0][0],diff);
}
   
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) scanf("%d",&mat[i][j]);
    int lb=0, ub=111;
    while (ub-lb>1) {
        int mid=(lb+ub)/2;
        if (C(mid)) ub=mid;
        else lb=mid;
    }
    printf("%d\n",ub);
}