#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int h, w;
string c[500];
int d[500][500];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
    cin>>h>>w;
    int sx=0, sy=0, gx=0, gy=0;
    for (int i=0; i<h; i++) {
        cin>>c[i];
        for (int j=0; j<w; j++) {
            if (c[i][j]=='s') {
                sx=i; sy=j;
            }
            if (c[i][j]=='g') {
                gx=i; gy=j;
            }
        }
    }
    memset(d, -1, sizeof(d));
    queue<pair<int, P> > que;
    que.push(make_pair(0,P(sx,sy)));
    d[sx][sy]=0;
    while (!que.empty()) {
        int x=que.front().second.first, y=que.front().second.second;
        int cnt=que.front().first;
        que.pop();
        if (d[x][y]<cnt) continue;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx>=0&&nx<h&&ny>=0&&ny<w) {
                int nc=cnt+(c[nx][ny]=='#');
                if (nc>=3) continue;
                if (d[nx][ny]==-1||d[nx][ny]>cnt) {
                    que.push(make_pair(nc,P(nx,ny)));
                    d[nx][ny]=nc;
                }
            }
        }
    }
    if (d[gx][gy]!=-1&&d[gx][gy]<3) puts("YES");
    else puts("NO");
}