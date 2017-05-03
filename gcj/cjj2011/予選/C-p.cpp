#include <cstdio>

// O(n^2)?
int solve(int r, int k, int n, int g[]) {
	int res = 0, npos = 0;
	for (int i=0; i<r; i++) {
		int cnt = 0;
		for (int i=0; i<n; i++,npos++) {
			if (npos == n) npos = 0;
			if (k-cnt<g[npos]) break;
			cnt += g[npos];
		}
		res += cnt;
	}
	return res;
}

int main() {
	int t, r, k, n;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		scanf("%d%d%d", &r, &k, &n);
		int g[n];
		for (int j=0; j<n; j++) scanf("%d", &g[j]);
		printf("Case #%d: %d\n", i, solve(r,k,n,g));
	}
	return 0;
}