#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int R, n;
	while (scanf("%d%d", &R, &n)) {
		if (R == -1 && n == -1) break;
		int army[n];
		for (int i=0; i<n; i++) scanf("%d", &army[i]);
		sort(army, army+n);
		int res = 0, i = 0;
		while (i < n) {
			int s = army[i++];
			while (i<n&&army[i]<=s+R) i++;
			int p = army[i-1];
			while (i<n&&army[i]<=p+R) i++;
			res++;
		}
		printf("%d\n", res);
	}
}
