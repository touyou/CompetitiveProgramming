#include <cstdio>
int n, k;
int r[202];
int main() {
  scanf("%d%d",&n,&k);
  for (int i=0; i<2*n+1; i++) scanf("%d",&r[i]);
  int cnt=0;
  for (int i=1; cnt<k&&i<2*n+1; i+=2) {
	if (r[i-1]==r[i]-1||r[i+1]==r[i]-1) continue;
	r[i]--; cnt++;
  }
  for (int i=0; i<2*n+1; i++) printf("%d%c",r[i],i==2*n?'\n':' ');
}
