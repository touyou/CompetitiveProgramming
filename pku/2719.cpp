#include <cstdio>

bool check(int n) {
	int s = n, p;
	while (s != 0) {
		p = s % 10;
		if (p == 4) return false;
		s = s / 10;
	}
	return true;
}

int main() {
	int n, pos = 0;
	int map[550000];
	for (int i = 1; i < 1000000; i++) {
		if (check(i)) {
			map[pos++] = i;
		}
	}
	while (scanf("%d", &n) && n != 0) {
		int i;
		for (i = 0; i < 550000; i++) {
			if (map[i] == n) break;
		}
		printf("%d: %d\n", n, i+1);
	}
}
