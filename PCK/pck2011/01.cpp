#include <cstdio>
int main() {
	int t, n;
	while (scanf("%d", &t)) {
		if (t == 0) break;
		scanf("%d", &n);
		int s, f;
		int tmp = 0;
		for (int i=0; i<n; i++) {
			scanf("%d%d", &s,&f);
			tmp += (f-s);
		}
		if (tmp < t) {
			printf("%d\n", t-tmp);
		} else {
			printf("OK\n");
		}
	}
}  
