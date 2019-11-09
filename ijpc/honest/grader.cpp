#include<cstdio>
#include<cstdlib>
#include"grader.h"
#include"honest.h"

static const int MAXN = 100000;
static int N, X[MAXN], A[MAXN];
static int cnt, cnt_ans, imp, ans[MAXN];

int question(int Q, int i, int j)
{
  if(Q != 1 && Q != 2)
    exit(92);
  if(i < 0 || i >= N)
    exit(92);
  if(Q == 1 && (j < 0 || j >= N))
    exit(92);

  cnt++;

  if(Q == 1)
    return X[i] ? X[j] : 1-X[j];
  else
    return A[i];
}

void answer(int i, int X)
{
  if(X != 0 && X != 1)
    exit(92);
  if(i < 0 || i >= N)
    exit(92);
  if(ans[i] != -1)
    exit(92);
  if(imp == 1)
    exit(92);

  cnt_ans++;

  ans[i] = X;
  imp = 0;
}

void impossible()
{
  if(imp != -1)
    exit(92);

  imp = 1;
}

int main()
{
  if(scanf("%d", &N) != 1) {
    fprintf(stderr, "read error\n");
    return 1;
  }

  for(int i=0; i<N; ++i) {
    if(scanf("%d", &X[i]) != 1) {
      fprintf(stderr, "read error\n");
      return 1;
    }
  }
  for(int i=0; i<N; ++i) {
    if(scanf("%d", &A[i]) != 1) {
      fprintf(stderr, "read error\n");
      return 1;
    }
  }

  for(int i=0; i<N; ++i)
    ans[i] = -1;
  cnt = 0;
  cnt_ans = 0;
  imp = -1;

  identify(N);

  if(imp != 1 && cnt_ans != N)
    exit(92);

  fprintf(stderr, "#question = %d\n", cnt);
  if(imp == 1) {
    puts("Impossible.");
  } else {
    for(int i=0; i<N; ++i)
      printf("%d%c", ans[i], i==N-1 ? '\n' : ' ');
  }

  return 0;
}
