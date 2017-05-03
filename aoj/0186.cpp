#include <cstdio>
int q1, b, c1, c2, q2;
int main() {
  while (scanf("%d", &q1)) {
	if (q1 == 0) break;
	scanf("%d%d%d%d",&b,&c1,&c2,&q2);
	int jidori = b / c1;
	jidori = (jidori < q2 ? jidori : q2);
	b -= jidori * c1;
	int normal = b / c2;
	b -= normal * c2;
	while (jidori + normal < q1) {
	  if (jidori <= 0) break;
	  jidori--; b += c1;
	  int temp = b / c2;
	  normal += temp;
	  b -= c2 * temp;
	}
	if (jidori <= 0) puts("NA");
	else printf("%d %d\n",jidori,normal);
  }
}
