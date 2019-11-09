#include <cstdio>

int gcd(int a, int b) { return b!=0?gcd(b,a%b):b; }

// O(n!)
int solve(int a, int b, int p) {
	int cnt = 0;
	for (int i=a; i<b; i++) {
		for (int j=i+1; j<=b; j++) {
			if (gcd(i,j) >= p) cnt++;
		}
	}
	return b-a+1-cnt;
}

int main() {
	int c, a, b, p;
	scanf("%d", &c);
	for (int i=1; i<=c; i++) {
		scanf("%d%d%d", &a, &b, &p);
		printf("Case #%d: %d\n", i, solve(a,b,p));
	}
	return 0;
}