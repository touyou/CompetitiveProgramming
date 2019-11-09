#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, b;
	scanf("%d%d",&n,&b);
	vector<int> cow(n);
	for (int i=0; i<n; i++) scanf("%d",&cow[i]);
	sort(cow.rbegin(), cow.rend());
	int res, sum=0;
	for (res=0; res<n; res++) {
		if (sum >= b) break;
		sum += cow[res];
	}
	printf("%d\n",res);
}