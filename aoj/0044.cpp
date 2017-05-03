#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	bool isprime[70001];
	int prime[35000];
	int pnum = 0;
	fill(isprime, isprime+70001, true);
	isprime[0] = isprime[1] = false;
	for (int i=2; i<70001; i++) {
		if (isprime[i]) {
			for (int j=i+i; j<70001; j+=i) isprime[j] = false;
		}
	}
	for (int i=2; i<70001; i++) {
		if (isprime[i]) {
			prime[pnum++] = i;
		}
	}
/*	for (int i=0; i<100; i++) {
		printf("%d ",prime[i]);
	}
	printf("\n");
*/
	while (scanf("%d", &n)!=EOF) {
		int a, b;
		for (int i=0; i<35000; i++) {
			if (prime[i] > n) {
				a = prime[i-1];
				b = prime[i];
				break;
			} else if (prime[i] == n) {
				a = prime[i-1];
				b = prime[i+1];
				break;
			}
		}
		printf("%d %d\n", a, b);
	}
}
