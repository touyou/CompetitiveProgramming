#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct t {
	int cost, flag;
	t() { flag = 1; }
};
class Comp {
	public:
		bool operator() (const t& a, const t& b) {
			return abs(a.cost) < abs(b.cost);
		}
};
int main() {
	int T, N;
	scanf("%d%d",&T,&N);
	t town[N];
	for (int i=0; i<N; i++) scanf("%d",&town[i].cost);
	int npos = 0, been = 0, res = 0;
	sort(town, town+N, Comp());
	for (res=0; res<N; res++) {
		been += abs(town[res].cost-npos);
		if (been>T) break;
		npos = town[res].cost;
	}
	printf("%d\n", res);
}