#include <cstdio>
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int res = n, tmp = n;
		while (1) {
			res += tmp/k;
			tmp = tmp/k + tmp%k;
			if (tmp < k) break;
		}
		printf("%d\n", res);
	}
}
