#include <cstdio>
int main() {
	int a,b,c,n;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	int trib[n];
	trib[0]=a; trib[1]=b; trib[2]=c;
	for (int i=3; i<n; i++) trib[i]=trib[i-1]+trib[i-2]+trib[i-3];
	printf("%d\n", trib[n-1]);
}