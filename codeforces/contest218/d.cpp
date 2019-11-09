#include <cstdio>
int fib[1000005];
int n, r;
int main() {
  scanf("%d%d",&n,&r);
  fib[0]=0; fib[1]=1;
  for (int i=2; i<=n; i++) fib[i]=fib[i-1]+fib[i-2];
  int dist=r-fib[n];
  if (dist==0) {
	puts("0");
	for (int i=0; i<n; i++) {
	  if (i%2==0) printf("T");
	  else printf("B");
	}
	puts("");
  } else {
  
  }
}
