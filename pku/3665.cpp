#include <cstdio>
#include <algorithm>
using namespace std;
int N, T;
int main() {
	scanf("%d%d", &N,&T);
	int s[N];
	for (int i=0; i<N; i++) scanf("%d",&s[i]);
	for (int i=0; i<T; i++) {
		int res = 0, high = 0;
		for (int i=0; i<N; i++) if (high<s[i]) {
			high = s[i];
			res = i;
		}
		printf("%d\n", res+1);
		int m = s[res]/(N-1);
		int temp = s[res] - m*(N-1);
		for (int i=0; i<N; i++) if (i!=res) {
			s[i] += m;
			if (temp) {
				s[i]++;
				temp--;
			}
		}
		s[res]=0;
	}
}