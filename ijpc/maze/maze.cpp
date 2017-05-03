#include "maze.h"
#include "grader.h"
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;
int mp[5][5];
int dist[1000][1000];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void taro(int W, int H, int M[1000][1000])
{
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) mp[i][j]=query(j-2, i-2);
    int rx=-1, ry=-1;
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) {
        if (M[i][j]==mp[2][2]) {
            bool flag=true;
            for (int k=0; k<5&&flag; k++) for (int l=0; l<5&&flag; l++) {
                int ny=i+k-2, nx=j+k-2;
                int nextp=0;
                if (nx<0&&nx>=W&&ny<0&&ny>=H) nextp=1;
                else nextp=M[ny][nx];
                if (nextp!=mp[k][l]) flag=false;
            }
            if (flag) {
                ry=i; rx=j;
            }
        }
    }
    for (int i=0; i<ry; i++) send(1);
    for (int i=0; i<rx; i++) send(0);
}

int jiro(int W, int H, int S, int X[])
{
    int tx=0, ty=0, jx=0, jy=0;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) mp[i][j]=query(j-2, i-2);
    for (int i=W*H; i<S; i++) {
        if (X[i]==1) ty++;
        else tx++;
    }
    queue<pair<int, P> > que;
    memset(dist, -1, sizeof(dist));
    que.push(make_pair(0,P(ty,tx)));
    while (!que.empty()) {
        int x=que.front().first;
        P p=que.front().second;
        que.pop();
        if (dist[p.first][p.second]!=-1) continue;
        dist[p.first][p.second]=x;
        for (int i=0; i<4; i++) {
            int ny=p.first+dy[i], nx=p.second+dx[i];
            if (nx>=0&&nx<W&&ny>=0&&ny<H&&M[ny][nx]==0) {
                que.push(make_pair(x+1,P(ny,nx)));
            }
        }
    }
    return dist[jy][jx];
}
