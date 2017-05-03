#include "variance.h"
#include <cstdio>

int main() {
  int n; scanf("%d", &n);
  int *a = new int[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  init(n,a);
  int q; scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int typ,arg1,arg2;
    scanf(" %d%d%d", &typ, &arg1, &arg2);
    if(typ==1) {
      printf("%d\n", variance(arg1,arg2));
      fflush(stdout);
    } else if(typ==0) {
      update(arg1,arg2);
    }
  }
  delete[] a;
  return 0;
}

