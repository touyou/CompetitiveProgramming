#include <cstdio>
int main() {
	int n; scanf("%d",&n);
	int res=1;
	for (int i=0; i<n; i++) res = res * 3 % 100000;
	printf("%d\n",res);
}