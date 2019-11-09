#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define INF INT_MAX
int bfs(int cow[], int npos, int N, int diff, int sum) {
	if (diff<sum) return INF;
	if (npos==N) return diff-sum;
	return min(bfs(cow,npos+1,N,diff,sum+cow[npos]),bfs(cow,npos+1,N,diff,sum));
}
int main() {
	int N, B, sum = 0;
	scanf("%d%d",&N,&B);
	int cow[N];
	for (int i=0; i<N; i++) {
		scanf("%d",&cow[i]);
		sum += cow[i];
	}
	int diff = sum - B;
	printf("%d\n",bfs(cow,0,N,diff,0));
}