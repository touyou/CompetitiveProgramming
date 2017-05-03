#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;
struct edge { 
	int to, cost;
	edge(int _to, int _cost) { to = _to; cost = _cost; }
};
typedef pair<int, int> P;
int main() {
	int T, N;
	scanf("%d%d",&T,&N);
	vector<edge> G[N];
	int d[N];
	for (int i=0; i<T; i++) {
		int x, y, cost;
		scanf("%d%d%d", &x,&y,&cost);
		G[x-1].push_back(edge(y-1,cost));
		G[y-1].push_back(edge(x-1,cost));	
	}
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+N, INT_MAX);
	d[N-1] = 0;
	que.push(P(0,N-1));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	printf("%d\n", d[0]);
}
