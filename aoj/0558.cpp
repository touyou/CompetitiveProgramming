#include <iostream>
#include <map>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int, int> P;
int h, w, n;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int d[1000][1000];
string field[1000];
P pos[10];
int bfs(P s, P g) {
    queue<P> que;
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) d[i][j]=INF;
    que.push(P(s.first, s.second));
    d[s.first][s.second]=0;
    while (!que.empty()) {
        P p = que.front(); que.pop();
        if (p.first==g.first&&p.second==g.second) break;
        for (int i=0; i<4; i++) {
            int nx=p.first+dx[i], ny=p.second+dy[i];
            if (0<=nx&&nx<h&&0<=ny&&ny<w&&field[nx][ny]!='X'&&d[nx][ny]==INF) {
                que.push(P(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    return d[g.first][g.second];
}
int main() {
    scanf("%d%d%d",&h,&w,&n);
    for (int i=0; i<h; i++) {
        cin >> field[i];
        for (int j=0; j<w; j++) {
            if (field[i][j]>'0'&&field[i][j]<='9') {
                pos[field[i][j]-'0']=make_pair(i,j);
            } else if (field[i][j]=='S') {
                pos[0]=make_pair(i,j);
            }
        }
    }
    int res=0;
    for (int i=0; i<n; i++) {
        res+=bfs(pos[i], pos[i+1]);
    }
    printf("%d\n",res);
}
