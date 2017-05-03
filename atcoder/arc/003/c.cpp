#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#define eps 1e-9
#define T 0.99
using namespace std;
typedef pair<int, int> P;
int n, m, sx, sy, gx, gy;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
double dlg[9][500000];
bool used[500][500];
string mp[500];
bool isin(int x, int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}
bool isgo() {
    queue<P> que;
    que.push(P(sx,sy));
    memset(used, 0, sizeof(used));
    used[sx][sy]=true;
    while (!que.empty()) {
        P p=que.front(); que.pop();
        int x=p.first, y=p.second;
        if (x==gx&&y==gy) return true;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (isin(nx,ny)&&!used[nx][ny]&&mp[nx][ny]!='#') {
                que.push(P(nx,ny));
                used[nx][ny]=true;
            }
        }
    }
    return false;
}

bool C(double r) {
    queue<pair<int, P> > que;
    que.push(make_pair(1, P(sx,sy)));
    memset(used, 0, sizeof(used));
    while (!que.empty()) {
        int t=que.front().first;
        P p=que.front().second; que.pop();
        int x=p.first, y=p.second;
        if (used[x][y]) continue;
        used[x][y]=true;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (isin(nx,ny)&&!used[nx][ny]&&mp[nx][ny]!='#') {
                if (mp[nx][ny]=='g') return true;
                int lg=mp[nx][ny]-'0'-1;
                if (dlg[lg][t]<r) continue;
                //printf("%d %d %d %d %.3f\n",nx,ny,t,lg,dlg[lg][t]);
                que.push(make_pair(t+1, P(nx, ny)));
            }
        }
    }
    return false;
}

int main() {
    for (int i=0; i<9; i++) {
        dlg[i][0]=i+1;
        for (int j=1; j<500000; j++) {
            dlg[i][j]=dlg[i][j-1]*T;
        }
    }
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        cin>>mp[i];
        for (int j=0; j<m; j++) {
            if (mp[i][j]=='s') {
                sx=i; sy=j;
            }
            if (mp[i][j]=='g') {
                gx=i; gy=j;
            }
        }
    }
    if (!isgo()) puts("-1");
    else {
        double lb=0.0, ub=10.0;
        for (int i=0; i<100; i++) {
            double mid=(lb+ub)/2.0;
            if (C(mid)) lb=mid;
            else ub=mid;
        }
        printf("%.10f\n",lb);
    }
}