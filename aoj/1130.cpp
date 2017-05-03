#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> P;
int w, h;
string f[20];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool isin(int x, int y) { return x>=0&&x<h&&y>=0&&y<w; }
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        int sx=-1,sy=-1;
        for (int i=0; i<h; i++) {
            cin>>f[i];
            for (int j=0; j<w; j++) if (f[i][j]=='@') {
                sx=i; sy=j;
                f[i][j]='#';
            }
        }
        queue<P> que;
        que.push(P(sx,sy));
        int res=1;
        while (!que.empty()) {
            int x=que.front().first, y=que.front().second;
            que.pop();
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (isin(nx,ny)&&f[nx][ny]=='.') {
                    que.push(P(nx,ny));
                    f[nx][ny]='#';
                    res++;
                }
            }
        }
        printf("%d\n",res);
    }
}
