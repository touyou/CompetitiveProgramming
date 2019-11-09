#include <cstdio>
int n, a[100];
int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  int set = 1;
  while (scanf("%d",&n)) {
	if (!n) break;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	int sum = 0;
	for (int i=0; i<n; i++) sum += a[i];
	sum /= n;
	int res = 0;
	for (int i=0; i<n; i++) {
	  if (a[i] >= sum) {
		res += a[i]-sum;
	  }
	}
	printf("Set #%d\nThe minimum number of moves is %d.\n\n",set++,res);
  }
}
