#include<cstdio>
int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
		int tmp;
		for (int i=0; i<n; i++) {
			scanf("%d", &tmp);
			if (tmp < 10) a++;
			else if (tmp < 20) b++;
			else if (tmp < 30) c++;
			else if (tmp < 40) d++;
			else if (tmp < 50) e++;
			else if (tmp < 60) f++;
			else g++;
		}
		printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g);
	}
}