#include <cstdio>
#include <cstring>

int main() {
	int n, r, p, c;
	while (scanf("%d%d", &n, &r)) {
		if (n == 0 && r == 0) break;
		int deck[n];
		for (int i=0; i<n; i++) deck[i] = n - i;
		for (int ix=0; ix<r; ix++) {
			scanf("%d%d", &p, &c);
			int temp[n];
			memcpy(temp, deck, sizeof(deck));
			for (int i=0; i<p-1; i++) {
				temp[i+c] = deck[i];
			}
			for (int i=p-1; i<p+c-1; i++) {
				temp[i-p+1] = deck[i];
			}
			memcpy(deck, temp, sizeof(temp));
			// for (int i=0; i<n; i++) printf("%d ", deck[i]);
			// printf("\n");
		}
		printf("%d\n", deck[0]);
	}
	return 0;
}