#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
struct edge {
	int to, cost;
	edge(int _to, int _cost) { to=_to; cost=_cost; }
};
typedef pair<int, int> P;
int N,R;
void solve(vector<edge> G[]) {
	int d[N], d2[N];
	fill(d,d+N,INT_MAX);
	fill(d2,d2+N,INT_MAX);
	priority_queue<P, vector<P>, greater<P> > que;
	d[0]=0;
	que.push(P(0,0));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second, dist = p.first;
		if (d2[v] < dist) continue;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			int dist2 = dist + e.cost;
			if (d[e.to] > dist2) {
				swap(d[e.to], dist2);
				que.push(P(d[e.to], e.to));
			}
			if (d2[e.to] > dist2 && d[e.to] < dist2) {
				d2[e.to] = dist2;
				que.push(P(d2[e.to], e.to));
			}
		}
	}
	printf("%d\n",d2[N-1]);
}
int main() {
	scanf("%d%d",&N,&R);
	vector<edge> G[N];
	for (int i=0; i<R; i++) {
		int f, t, d;
		scanf("%d%d%d",&f,&t,&d);
		G[f-1].push_back(edge(t-1,d));
		G[t-1].push_back(edge(f-1,d));
	}
	solve(G);
}