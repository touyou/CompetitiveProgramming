#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct npos {
    int x, y, t;
    npos(int _x, int _y, int _t) {
        x=_x; y=_y; t=_t;
    }
};
int m;
int board[400][400];
bool visited[400][400];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool isin(int x, int y) { return x>=0&&y>=0; }
int main() {
    for (int i=0; i<400; i++) for (int j=0; j<400; j++) board[i][j]=2000;
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        int x, y, t; scanf("%d%d%d",&x,&y,&t);
        board[x][y]=min(board[x][y],t);
        for (int j=0; j<4; j++) {
            int nx=x+dx[j], ny=y+dy[j];
            if (isin(nx,ny)) board[nx][ny]=min(board[nx][ny],t);
            // printf("%d %d %d\n",nx,ny,isin(nx,ny)?1:0);
        }
    }
    /*for (int i=0; i<10; i++) for (int j=0; j<10; j++) {
        printf("%d%c",board[i][j],j==9?'\n':' ');
    }*/
    queue<npos> que;
    que.push(npos(0,0,0));
    while (!que.empty()) {
        npos n=que.front(); que.pop();
        if (visited[n.x][n.y]) continue;
        visited[n.x][n.y]=true;
        if (board[n.x][n.y]==2000) {
            printf("%d\n",n.t);
            return 0;
        }
        // printf("%d %d %d\n",n.x,n.y,n.t);
        for (int i=0; i<4; i++) {
            int nx=n.x+dx[i], ny=n.y+dy[i];
            if (isin(nx,ny)&&!visited[nx][ny]) {
                if (board[nx][ny]<=n.t+1) continue;
                else {
                    que.push(npos(nx,ny,n.t+1));
                }
            }
        }
    }
    puts("-1");
}
