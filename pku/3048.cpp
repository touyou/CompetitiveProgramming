#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int isprime[20001],psize=0;
	fill(isprime, isprime+20001, 1);
	isprime[0]=isprime[1]=0;
	for (int i=2; i<20001; i++) {
		if (isprime[i]) {
			for (int j=i+i; j<20001; j+=i) isprime[j]=0;
			psize++;
		}
	}
	int prime[++psize], npos=1;
	prime[0]=1;
	for (int i=2; i<20001; i++) {
		if (isprime[i]) prime[npos++]=i;
	}
	int n; scanf("%d",&n);
	int num[n],m=0;
	for (int i=0; i<n; i++) {
		scanf("%d",&num[i]);
		m=max(m,num[i]);
	}
	int p;
	for (p=0; p<psize; p++) if (prime[p]>=m) break;
	int res = 0;
	for (;p>=0;p--) {
		for (int i=0; i<n; i++) if (num[i]%prime[p]==0) {
			res=num[i];
			break;
		}
		if (res) break;
	}
	printf("%d\n",res);
}