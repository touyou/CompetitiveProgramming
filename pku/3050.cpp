#include <cstdio>
#include <set>
using namespace std;
int mp[5][5];
set<int> res;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int t[6]={100000, 10000, 1000, 100, 10, 1};
void dfs(int x, int y, int v, int cnt) {
    v+=mp[x][y]*t[cnt];
    if (cnt==5) {
        res.insert(v);
        return;
    }
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<0||nx>4||ny<0||ny>4) continue;
        dfs(nx,ny,v,cnt+1);
    }
    return;
}
int main() {
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) scanf("%d",&mp[i][j]);
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) dfs(i,j,0,0);
    printf("%d\n",res.size());
}