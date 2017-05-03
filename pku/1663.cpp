#include <cstdio>

int main() {
	int N, x, y;
	scanf("%d", &N);
	for (int ix=0; ix<N; ix++) {
		scanf("%d%d",&x,&y);
		if (!(x==y)&&!(x-y==2)) {
			printf("No Number\n");
			continue;
		}
		int res = 0;
		if (x == y) {
			for (int i=0; i<x; i++) {
				if (i%2 == 0) res++;
				else res += 3;
			}
		} else {
			res = 2;
			for (int i=0; i<x-2; i++) {
				if (i%2 == 0) res++;
				else res += 3;
			}
		}
		printf("%d\n", res);
	}
}