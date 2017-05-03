#include <cstdio>
int main() {
	int a, b, m;
	scanf("%d%d%d",&a,&b,&m);
	int div = b / a;
	int res = 0;
	while (div%m==0) {
		div /= m;
		res++;
	}
	printf("%d\n",res);
}