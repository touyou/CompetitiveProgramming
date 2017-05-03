#include <cstdio>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int x, y, n;
int field[1001][1001];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main() {
    scanf("%d%d%d",&x,&y,&n);
    for (int i=0; i<n; i++) {
        int a, b; scanf("%d%d",&a,&b);
        field[a+500][b+500]=1;
    }
    queue<pair<P,int> > que;
    que.push(make_pair(P(500,500),0));
    int res=0;
    while (!que.empty()) {
        pair<P, int> p=que.front(); que.pop();
        int ax=p.first.first,ay=p.first.second;
        int cnt=p.second;
        if (ax==x+500&&ay==y+500) {
            res=cnt;
            break;
        }
        if (field[ax][ay]==1) continue;
        field[ax][ay]=1;
        for (int i=0; i<4; i++) {
            int nx=ax+dx[i], ny=ay+dy[i];
            if (nx>=0&&nx<1001&&ny>=0&&ny<1001&&field[nx][ny]==0) {
                que.push(make_pair(P(nx,ny),cnt+1));
            }
        }
    }
    printf("%d\n",res);
}
