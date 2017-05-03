#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n, m;
vector<int> G[100];
set<int> in[100], out[100];
bool used[100];
void calc(int x) {
    memset(used, 0, sizeof(used));
    queue<int> que;
    que.push(x);
    while (!que.empty()) {
        int nx=que.front(); que.pop();
        if (used[nx]) continue;
        used[nx]=true;
        for (int i=0; i<G[nx].size(); i++) {
            int y=G[nx][i];
            in[y].insert(x);
            out[x].insert(y);
            que.push(y);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b); a--; b--;
        G[a].push_back(b);
    }
    int res=0;
    for (int i=0; i<n; i++) {
        calc(i);
    }
    for (int i=0; i<n; i++) {
        if (in[i].size()+out[i].size()+1==n) res++;
    }
    printf("%d\n",res);
}
