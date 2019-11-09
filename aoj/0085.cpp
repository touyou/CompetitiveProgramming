#include <cstdio>

int dfs(int n, int k) {
	if (n == 1) return 0;
	return (dfs(n-1,k)+k)%n;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		printf("%d\n", dfs(n,m)+1);
	}
}