#include <cstdio>
int main() {
	int n,r,e,c;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d%d%d",&r,&e,&c);
		e-=c;
		if (r==e) printf("does not matter\n");
		else if (r>e) printf("do not advertise\n");
		else printf("advertise\n");
	}
}