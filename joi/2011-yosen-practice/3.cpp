#include <cstdio>
int main() {
	int n; scanf("%d",&n);
	int a=0, b=0;
	for (int i=0; i<n; i++) {
		int ap, bp; scanf("%d%d",&ap,&bp);
		if (ap>bp) a++;
		else if (ap<bp) b++;
	}
	printf("%d %d\n",a,b);
}