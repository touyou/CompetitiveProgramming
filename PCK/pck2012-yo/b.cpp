#include <cstdio>
int main() {
  int a, b, c;
  scanf("%d%d%d",&a,&b,&c);
  if ((a&&!b&&!c)||(!a&&b&&!c)||(!a&&!b&&!c)) puts("Close");
  else puts("Open");
}
