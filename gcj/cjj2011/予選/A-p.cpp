#include <cstdio>
#include <algorithm>
using namespace std;
// O(nk)
int solve(int n, int k) {
	int state[n];
	fill(state, state+n, 0);
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			if (state[j]^=1) break;
		}
	}
	return state[n-1];
}

int main() {
	int t, n, k;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		scanf("%d%d", &n, &k);
		int res = solve(n, k);
		if (res) printf("Case #%d: ON\n", i);
		else printf("Case #%d: OFF\n", i);
	}
	return 0;
}