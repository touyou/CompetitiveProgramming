#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	while (scanf("%d",&n)&&n!=0) {
		vector<int> cast(n);
		for (int i=0; i<n; i++) scanf("%d",&cast[i]);
		sort(cast.begin(), cast.end());
		long long res = 0;
		long long mati = 0;
		for (int i=0; i<n; i++) {
			res += mati;
			mati += cast[i];
		}
		printf("%lld\n", res);
	}
}
