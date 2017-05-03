#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N, S;
	scanf("%d%d",&N,&S);
	int cows[N];
	for (int i=0; i<N; i++) scanf("%d",&cows[i]);
	sort(cows, cows+N);
	int res = 0;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			if (cows[i]+cows[j]>S) break;
			res++;
		}
	}
	printf("%d\n",res);
}