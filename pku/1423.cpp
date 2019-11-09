#include <cstdio>
#include <cmath>
#define ME 2.71828183
#define MPI 3.14159265

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &m);
		int t=m*log10(m)-m*log10(ME)+log10(2*MPI*m)/2.0+1;
		if (m < 2) t = 1;
		printf("%d\n", t);
	}
}
