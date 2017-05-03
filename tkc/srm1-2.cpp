#include <cstdio>
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if (a==0) {
		printf("TKC\n");
		return 0;
	}
	printf("%f\n", (double)(b-c)/(double)a);
}