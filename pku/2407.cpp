#include <cstdio>
#include <algorithm>
using namespace std;
bool isprime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i=3; i*i<=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int n, pnum=0;
	bool prime[999999999];
	int p[500000000];
	fill(prime, prime+999999999, true);
	prime[0]=prime[1]=false;
	for (int i=2; i<999999999; i++) {
		if (prime[i]) {
			p[pnum++] = i;
			for (int j=i+i; j<999999999; j+=i) prime[j]=false;
		}
	}
	while (scanf("%d", &n) && n != 0) {
		if (isprime(n)) {
			printf("%d\n", n-1);
			continue;
		}
		int cnt=0;
		for (int i=0; i<500000000; i++) {
			if (p[i] > n) break;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
