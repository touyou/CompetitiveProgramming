#include <cstdio>
int main() {
	int N, C;
	scanf("%d",&N);
	for (int i=0; i<N; i++) {
		scanf("%d",&C);
		int Q, D, n, P;
		Q = C / 25;
		C -= Q * 25;
		D = C / 10;
		C -= D * 10;
		n = C / 5;
		C -= n * 5;
		P = C;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
				i+1, Q, D, n, P);
	}
}
