// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// struct dt {
	// int a, b;
// };
// class dtComp {
	// public:
		// bool operator() (const dt& x, const dt& y) {
			// return x.a < y.b;
		// }
// };
// int main() {
	// int n, l, p; scanf("%d", &n);
	// dt dts[n];
	// for (int i=n-1; i>=0; i--) scanf("%d%d", &dts[i].a, &dts[i].b);
	// scanf("%d%d", &l, &p);
	// for (int i=0; i<n; i++) dts[i].a = l - dts[i].a;
	// sort(dts, dts+n, dtComp());
	// int npos = 0, res = 0, i = 0;
	// priority_queue<int> que;
	// while (1) {
		// for (;i<n;i++) {
			// if (dts[i].a > npos + p) break;
			// que.push(dts[i].b);
		// }
		// npos += p;
		// if (npos >= l) break;
		// else if (que.empty()) break;
		// p = que.top(); que.pop();
		// res++;
	// }
	// if (npos < l) printf("-1\n");
	// else printf("%d\n", res);
// }
// int main() {
	// int n, l, p; scanf("%d", &n);
	// dt dts[n+1];
	// for (int i=n-1; i>=0; i--) scanf("%d%d", &dts[i].a, &dts[i].b);
	// scanf("%d%d", &l, &p);
	// for (int i=0; i<n; i++) dts[i].a = l - dts[i].a;
	// int npos = 0, res = 0, tank = p;
	// dts[n].a = l; dts[n].b = 0;
	// priority_queue<int> que;
	// for (int i=0; i<n+1; i++) {
		// int d = dts[i].a - npos;
		// while (tank - d < 0) {
			// if (que.empty()) {
				// puts("-1");
				// return 0;
			// }
			// tank += que.top(); que.pop();
			// res++;
		// }
		// tank -= d;
		// npos = dts[i].a;
		// que.push(dts[i].b);
	// }
	// printf("%d\n", res);
// }
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	vector<pair<int, int> > v;
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		int x, y;
		scanf("%d %d\n", &x, &y);
		v.push_back(make_pair(x, y));
	}
	int L, P;
	scanf("%d %d\n", &L, &P);
	sort(v.begin(), v.end());
	vector<pair<int, int> >::reverse_iterator rit = v.rbegin();
	priority_queue<int> pq;
	int cnt = 0;
	while(L){
		if(L == (*rit).first){
			pq.push((*rit).second);
			rit++;
		}
		if(P == 0){
			if(pq.empty()){
				cnt = -1;
				break;
			}
			P += pq.top();
			pq.pop();
			cnt++;
		}
		P--;L--;
	}
	printf("%d\n", cnt);
	return 0;
}