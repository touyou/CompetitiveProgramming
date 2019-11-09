#include <cstdio>
int main() {
	int K;
	while (scanf("%d",&K)) {
		if (K == 0) break;
		int res = 0;
		for (int i=0; i<K*(K-1)/2; i++) {
			int in; scanf("%d",&in);
			res += in;
		}
		printf("%d\n",res/(K-1));
	}
}