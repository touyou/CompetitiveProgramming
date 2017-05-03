#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main() {
	int n; scanf("%d", &n);
	int f[n];
	for (int i=0; i<n; i++) scanf("%d", &f[i]);
	ll res = 0;
	priority_queue<int, vector<int>, greater<int> > tree;
	for (int i=0; i<n; i++) tree.push(f[i]);
	while (tree.size() > 1) {
		int fir = tree.top(); tree.pop();
		int sec = tree.top(); tree.pop();
		int sum = fir + sec;
		res += sum;
		tree.push(sum);
	}
	printf("%lld\n", res);
}