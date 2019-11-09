#include <cstdio>
int main() {
	int n;
	while (scanf("%d",&n)) {
		if (n == 0) break;
		int res = 0;
		for (int i=0; i<n/4; i++) {
			int in; scanf("%d",&in);
			res += in;
		}
		printf("%d\n",res);
	}
}