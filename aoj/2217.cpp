#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
struct P { int x, y; };
int n;
int cnt[100][100];
P map[100][100];
int dfs(int y, int x, int c) {
    if (cnt[x][y]!=-1&&cnt[x][y]!=c) return cnt[x][y];
    if (cnt[x][y]==c) return cnt[x][y];
    cnt[x][y]=c;
    return cnt[x][y]=dfs(map[x][y].x,map[x][y].y,cnt[x][y]);
}
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) scanf("%d%d",&map[i][j].x,&map[i][j].y);
        }
        memset(cnt,-1,sizeof(cnt));
        int x=0;
        set<int> res;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (cnt[i][j]==-1) {
                    cnt[i][j]=++x;
                    cnt[i][j]=dfs(map[i][j].x,map[i][j].y,cnt[i][j]);
                    res.insert(cnt[i][j]);
                }
            }
        }
        printf("%d\n",res.size());
    }
}

