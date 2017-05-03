#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n;
bool used[100];
bool notused[100];
vector<int> G[100];
int dfs(int x, int cnt) {
    int res=cnt;
    used[x]=true;
    notused[x]=false;
    for (int i=0; i<G[x].size(); i++) {
        int y=G[x][i];
        if (used[y]) continue;
        res=max(res,dfs(y,cnt+1));
    }
    used[x]=false;
    return res;
}
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        memset(used, 0, sizeof(used));
        memset(notused, 0, sizeof(notused));
        for (int i=0; i<100; i++) G[i].clear();
        for (int i=0; i<n; i++) {
            int a, b; scanf("%d%d",&a,&b);
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
            notused[a-1]=notused[b-1]=true;
        }
        int res=0;
        for (int j=1;;j++) {
            for (int i=0; i<100; i++) {
                if (G[i].size()!=j) continue;
                res=max(res,dfs(i,1));
            }
            bool isbreak=true;
            for (int i=0; i<100; i++) {
                if (notused[i]) {
                    isbreak=false;
                    break;
                }
            }
            if (isbreak) break;
        }
        printf("%d\n",res);
    }
}
