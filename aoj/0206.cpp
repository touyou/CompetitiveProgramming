#include <cstdio>

int main() {
	int L, M, N;
	while (scanf("%d", &L)) {
		if (L == 0) break;
		int res = 0;
		bool flag = true;
		for (int i=0; i<12; i++) {
			scanf("%d%d", &M, &N);
			L -= (M - N);
			if (flag) {
				res++;
			}
			if (L <= 0) flag = false;
		}
		if (res == 12 && L > 0) {
			printf("NA\n");
		} else {
			printf("%d\n", res);
		}
	}
}
