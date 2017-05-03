#include <cstdio>
int main() {
  int t, n;
  while (scanf("%d",&t)) {
	if (t==0) break;
	scanf("%d",&n);
	int sum = 0;
	for (int i=0; i<n; i++) {
	  int s, f; scanf("%d%d",&s,&f);
	  sum += f - s;
	}
	if (sum >= t) puts("OK");
	else printf("%d\n",t-sum);
  }
}
