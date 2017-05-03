#include <set>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	set<ll> q;
	q.insert(1);
	vector<int> ans;
	while (ans.size() < 1500) {
		const ll val = *q.begin();
		q.erase(q.begin());
		ans.push_back(val);
		q.insert(val*2);
		q.insert(val*3);
		q.insert(val*5);
	}
	int n;
	while (scanf("%d", &n) && n != 0) printf("%d\n", ans[n-1]);
}
