#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		int ten = 10;
		for (int i=0; i<8; i++) {
			if (x<ten) break;
			int tmp = x % ten;
			if (tmp >= 5*ten/10) x += ten;
			x -= tmp;
			ten *= 10;
		}
		printf("%d\n", x);
	}
}
