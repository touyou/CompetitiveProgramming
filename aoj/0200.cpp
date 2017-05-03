#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> P;
struct train {
int to, cost;
train(int _to, int _cost) { to=_to; cost=_cost; }
};
int n,m,k,a,b,r;
void djk(vector<train> G[], int s, int g) {
	int d[m];
	fill(d, d+m, INT_MAX);
	d[s-1] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0,s-1));
	while(!que.empty()) {
		P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            train e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
	}
	printf("%d\n",d[g-1]);
}
int main() {
	while (scanf("%d%d",&n,&m)) {
		if (n==0&&m==0) break;
		vector<train> mcost[m], mtime[m];
		for (int i=0; i<n; i++) {
			int c, t;
			scanf("%d%d%d%d",&a,&b,&c,&t);
			mcost[a-1].push_back(train(b-1,c));
			mcost[b-1].push_back(train(a-1,c));
			mtime[a-1].push_back(train(b-1,t));
			mtime[b-1].push_back(train(a-1,t));
		}
		scanf("%d",&k);
		for (int i=0; i<k; i++) {
			scanf("%d%d%d",&a,&b,&r);
			if (r) djk(mtime,a,b);
			else djk(mcost,a,b);
		}
	}
}