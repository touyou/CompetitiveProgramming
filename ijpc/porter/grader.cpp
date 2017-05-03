#include <cstdio>
#include <cstdlib>
#include "porter.h"

const int MAXQ = 100000;

int main() {
  int E,S,Q;
  if(scanf("%d%d%d", &E, &S, &Q)<3) {
    fprintf(stderr, "read error\n");
    exit(1);
  }
  if( ! ( 0 <= E && E < S && S <= 100000 ) ) {
    fprintf(stderr, "invalid E,S\n");
    exit(1);
  }
  if( ! ( 1 <= Q && Q <= 100000 ) ) {
    fprintf(stderr, "invalid Q\n");
    exit(1);
  }
  static int X[MAXQ],Y[MAXQ],A[MAXQ],B[MAXQ];
  for(int i = 0; i < Q; i++) {
    if(scanf("%d%d%d%d", X+i, Y+i, A+i, B+i)<4) {
      fprintf(stderr, "read error\n");
      exit(1);
    }
    if( ! ( 0 <= X[i] && X[i] < E ) ) {
      fprintf(stderr, "invalid X[%d]\n", i);
      exit(1);
    }
    if( ! ( 0 <= Y[i] && Y[i] < E ) ) {
      fprintf(stderr, "invalid Y[%d]\n", i);
      exit(1);
    }
    if( ! ( 0 <= A[i] && A[i] < 1000000000 ) ) {
      fprintf(stderr, "invalid A[%d]\n", i);
      exit(1);
    }
    if( ! ( 0 <= B[i] && B[i] < 1000000000 ) ) {
      fprintf(stderr, "invalid B[%d]\n", i);
      exit(1);
    }
  }
  init(E,S);
  for(int i = 0; i < Q; i++) {
    int ret = moveTo(X[i], Y[i], A[i], B[i]);
    printf("%d\n", ret);
  }
  return 0;
}
