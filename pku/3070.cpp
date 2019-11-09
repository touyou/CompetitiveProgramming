#include <cstdio>
typedef long long ll; 
ll formula(int n) {
	if (n==0) return 0;
	ll a1=1, a2=1, b1=1, b2=0;
	for (int i=1; i<n; i++) {
		ll t1=a1, t2=a2, t3=b1, t4=b2;
		a1=t1+t2; a2=t1; b1=t3+t4; b2=t3;
	}
	return a2;
}
int main() {
	int n;
	while (scanf("%d",&n)&&n!=-1) printf("%d\n", formula(n)%10000);
}