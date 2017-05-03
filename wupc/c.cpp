#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define M INT_MAX/2
typedef pair<int, int> P;
int n, m, sx, sy, cx, cy, gx, gy;
int used[500][500];
int ret[500][500];
string mat[500];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int dfs(int x, int y, int tx, int ty) {
    memset(used, 0, sizeof(used));
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) ret[i][j]=M;
    ret[x][y]=0;
    used[x][y]=1;
    queue<P> que;
    que.push(P(x,y));
    while (!que.empty()) {
        P p=que.front(); que.pop();
        x=p.first; y=p.second;
        if (x==tx&&y==ty) continue;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (!used[nx][ny]&&mat[nx][ny]!='#') {
                ret[nx][ny]=ret[x][y]+1;
                used[nx][ny]=1;
                que.push(P(nx,ny));
            }
        }
    }
    if (ret[tx][ty]==M) return -1;
    else return ret[tx][ty];
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        cin>>mat[i];
        for (int j=0; j<m; j++) {
            if (mat[i][j]=='S') { sx=i; sy=j; }
            if (mat[i][j]=='C') { cx=i; cy=j; }
            if (mat[i][j]=='G') { gx=i; gy=j; }
        }
    }
    int r1=dfs(sx,sy,cx,cy);
    int r2=dfs(cx,cy,gx,gy);
    if (r1>0&&r2>0) printf("%d\n",r1+r2);
    else puts("-1");
}