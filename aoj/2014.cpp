#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;
int w,h,wnum, bnum;
string field[50];
bool isin(int x, int y) { return x>=0&&x<h&&y>=0&&y<w; }
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        wnum=bnum=0;
        for (int i=0; i<h; i++) cin>>field[i];
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (field[i][j]=='.') {
                    int cnt=1;
                    char flag='0';
                    field[i][j]='-';
                    queue<P> que;
                    que.push(P(i,j));
                    while (!que.empty()) {
                        P p=que.front(); que.pop();
                        for (int k=0; k<4; k++) {
                            int nx=p.first+dx[k], ny=p.second+dy[k];
                            if (!isin(nx,ny)) continue;
                            if (field[nx][ny]=='.') {
                                que.push(P(nx,ny));
                                field[nx][ny]='-';
                                cnt++;
                            }
                            if (flag=='0') {
                                if (field[nx][ny]=='W') {
                                    flag='W';
                                } else if (field[nx][ny]=='B') {
                                    flag='B';
                                }
                            } else if (field[nx][ny]=='W'&&flag=='B') {
                                flag='X';
                            } else if (field[nx][ny]=='B'&&flag=='W') {
                                flag='X';
                            }
                        }
                    }
                    if (flag=='W') wnum+=cnt;
                    if (flag=='B') bnum+=cnt;
                }
            }
        }
        // for (int i=0; i<h; i++) cout<<field[i]<<endl;
        printf("%d %d\n",bnum,wnum);
    }
}
