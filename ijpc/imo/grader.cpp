#include <cstdio>
#include "imo.h"

const int MAXN = 100000, MAXM = 200000;

static int N, M;
static int E[MAXM][2];

int main()
{
	if(scanf("%d%d", &N, &M) != 2)
	{
		fprintf(stderr, "read error\n");
		return 1;
	}
	for(int i=0; i<M; i++)
	{
		if(scanf("%d%d", &(E[i][0]), &(E[i][1])) != 2) {
			fprintf(stderr, "read error\n");
			return 1;
		}
	}
	printf("%lld\n", best_swap(N,M,E));
	return 0;
}
