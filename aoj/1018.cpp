#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N;
	while (scanf("%d",&N)!=EOF) {
		int P[N];
		for (int i=0; i<N; i++) scanf("%d",&P[i]);
		sort(P, P+N);
		int res = 0, sum = 0;
		for (int i=0; i<N; i++) {
			sum += P[i];
			res += sum;
		}
		printf("%d\n", res);
	}
}