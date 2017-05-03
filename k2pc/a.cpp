#include <cstdio>
int a,b,c,n;
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&n);
  int ra=n-a>=0?n-a:0;
  int rb=2*n-b>=0?2*n-b:0;
  int rc=3*n-c>=0?3*n-c:0;
  printf("%d %d %d\n",ra,rb,rc);
}
