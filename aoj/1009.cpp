#include <cstdio>
int gcd(int a, int b) {
	return b!=0?gcd(b,a%b):a;
}
int main() {
	int a, b;
	while (scanf("%d%d",&a,&b)!=EOF) printf("%d\n",gcd(a,b));
}