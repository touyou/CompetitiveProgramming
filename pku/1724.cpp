#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int k, n, r;
struct road {
    int d, l, t;
};
bool vis[100][10001];
vector<road> roads[100];
int main() {
    scanf("%d%d%d",&k,&n,&r);
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<r; i++) {
        int s, de, l, t;
        scanf("%d%d%d%d",&s,&de,&l,&t);
        roads[s-1].push_back((road){de-1,l,t});
    }
    priority_queue<PP, vector<PP>, greater<PP> > que;
    que.push(make_pair(0,P(0,0)));
    while (!que.empty()) {
        int len=que.top().first;
        int np=que.top().second.first;
        int sp=que.top().second.second;
        que.pop();
        if (vis[np][sp]) continue;
        vis[np][sp]=true;
        if (np==n-1) {
            printf("%d\n",len);
            return 0;
        }
        for (int i=0; i<roads[np].size(); i++) {
            road nr=roads[np][i];
            if (sp+nr.t>k||vis[nr.d][sp+nr.t]) continue;
            que.push(make_pair(len+nr.l,P(nr.d,sp+nr.t)));
        }
    }
    puts("-1");
}