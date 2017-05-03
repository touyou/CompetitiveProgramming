#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MA (1<<12)-1
int h, w, k;
string mp[50];
int dp[1<<12][5][55][55];
// 0(00) up 1(01) left 2(10) down 3(11) right
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int dfs(int move, int waste, int x, int y) {
    if (dp[move][waste][x][y]!=-1) return dp[move][waste][x][y];
    int nmv = (move<<2)&MA;

    int valt=-999999;

    for (int i=0; i<4; i++) {
        if (waste>=k&&i<2) continue;
        int nx=x+dx[i], ny=y+dy[i];
        if (0>nx||h<=nx||0>ny||w<=ny||mp[nx][ny]=='#') continue;
        valt=max(valt, dfs(nmv|i, waste+(i<2), nx, ny));
    }

    bool same=false;
    int u=move,px=x,py=y;
    for (int i=0; i<6; i++) {
        px-=dx[u&3]; py-=dy[u&3];
        if (!(px>=0&&py>=0&&px<h&&py<w)) break;
        if (px==x&&py==y) same=true;
        u>>=2;
    }
    if (!same&&mp[x][y]!='.') valt+=mp[x][y]-'0';

    if (valt<0&&x==h-1&&y==w-1) valt=1;
    //printf("%d %d: %d\n",x,y,valt);
    return dp[move][waste][x][y]=valt;
}

int main() {
    scanf("%d%d%d",&h,&w,&k);
    for (int i=0; i<h; i++) cin>>mp[i];
    memset(dp, -1, sizeof(dp));
    int res=dfs(0,0,0,0)-1;
    printf("%d\n",res<0?0:res);
}
