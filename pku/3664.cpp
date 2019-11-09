#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int main () {
	int n, k;
	scanf("%d%d",&n,&k);
	vector<PP> cows(n);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&cows[i].first,&cows[i].second.first);
		cows[i].second.second=i+1;
	}
	sort(cows.rbegin(), cows.rend());
	P res[k];
	for (int i=0; i<k; i++) {
		res[i].first=cows[i].second.first;
		res[i].second=cows[i].second.second;
	}
	sort(res, res+k);
	printf("%d\n", res[k-1].second);
}
	