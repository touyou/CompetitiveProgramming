#include <cstdio>
#include <vector>
using namespace std;
struct edge { int s, e, c; };
vector<edge> map;
bool efind(int n) {
	for (int i=0; i<map.size(); i++) {
		if (map[i].e == n) {
			if (map[i].s == 1) return true;
			if (efind(map[i].s)) return true;
		}
	}
	return false;
}
int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF) {
		int res = 0;
		map.clear();
		for (int i=0; i<N; i++) {
			edge e;
			scanf("%d%d%d", &e.s, &e.e, &e.c);
			map.push_back(e);
		}
		for (int i=0; i<N; i++) {
			if (map[i].e == M) {
				if (map[i].s == 1) {
					res += map[i].c;
					continue;
				}
				if (efind(map[i].e)) res += map[i].c;
			}
		}
		printf("%d\n", res);
	}
}
