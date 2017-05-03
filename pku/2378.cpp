#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int n, x, y;
bool used[100000];
vector<int> G[10000];
set<int> res;
int dfs(int np) {
    int ret=1;
    int csv=0;
    used[np]=true;
    for (int i=0; i<G[np].size(); i++) {
        if (used[G[np][i]]) continue;
        int tmp=dfs(G[np][i]);
        csv=max(csv, tmp);
        ret+=tmp;
    }
    csv=max(csv, n-ret);
    if (csv<=n/2) res.insert(np+1);
    return ret;
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        scanf("%d%d",&x,&y);
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    memset(used, 0, sizeof(used));
    dfs(0);
    if (res.size()==0) puts("NONE");
    else {
        for (set<int>::iterator i=res.begin(); i!=res.end(); i++) {
            printf("%d\n",*i);
        }
    }
}