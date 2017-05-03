#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#define inf INT_MAX/2
using namespace std;
int w, h, sx, sy;
string dun[33];
bool dis[28];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool isin(int nx, int ny) {
    return nx>=0&&nx<h&&ny>=0&&ny<w;
}
int dfs(int x, int y, int cnt) {
    int res=inf;
    if (dun[x][y]=='<') return cnt;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (isin(nx,ny)&&dun[nx][ny]=='.') {
            int r=dfs(nx,ny,cnt+1);
            if (r!=-1) res=min(res,r);
        } else if (isin(nx,ny)&&dun[nx][ny]>='a'&&dun[nx][ny]<='z') {
            dis[dun[nx][ny]-'a']=!dis[dun[nx][ny]-'a'];
            int r=dfs(nx,ny,cnt+1);
            if (r!=-1) res=min(res,r);
        } else if (isin(nx,ny)&&dun[nx][ny]>='A'&&dun[nx][ny]<='Z'&&dis[dun[nx][ny]-'A']) {
            int r=dfs(nx,ny,cnt+1);
            if (r!=-1) res=min(res,r);
        }
    }
    if (res==inf) return -1;
    return res;
}
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        fill(dis, dis+28, false);
        for (int i=0; i<h; i++) {
            cin>>dun[i];
            for (int j=0; j<w; j++) {
                if (dun[i][j]=='@') {
                    sx=i; sy=j;
                }
            }
        }
        dun[sx][sy]='.';
        printf("%d\n",dfs(sx,sy,0));
    }
}
