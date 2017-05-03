#include <cstdio>

int main() {
	int N;
	while (scanf("%d", &N) && N != 0) {
		int passed = 0, coins = 0;
		bool flag = false;
		for (int i = 1; ; i++) {
			for (int j = 0; j < i; j++) {
				passed++;
				coins += i;
				if (passed == N) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		printf("%d %d\n", N, coins);
	}
}
