#include <cstdio>
struct edge {
	int s, e;
};
int main() {
	int T;
	scanf("%d", &T);
	for (int ix=1; ix<=T; ix++) {
		int N, M, K;
		scanf("%d%d%d", &N, &M, &K);
		edge map[K];
		int res = 0;
		for (int i=0; i<K; i++) scanf("%d%d", &map[i].s, &map[i].e);
		for (int i=0; i<K-1; i++) {
			for (int j=i+1; j<K; j++) {
				if (map[i].s<map[j].s&&map[i].e>map[j].e) {
					res++;
				} else if (map[i].s>map[j].s&&map[i].e<map[j].e) {
					res++;
				}
			}
		}
		printf("Test case %d: %d\n",ix,res);
	}
}
