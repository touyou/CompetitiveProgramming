#include <cstdio>
typedef long long ll;
int main() {
	int n; scanf("%d",&n);
	ll res = 1;
	for (int i=1; i<=n; i++) res *= i;
	printf("%lld\n",res);
}