#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	ll n, m;
	while (scanf("%lld%lld", &n, &m)) {
		if (n == 0 && m == 0) break;
		double res = 0.0;
		int ng[m];
		for (int i=0; i<m; i++) scanf("%d", &ng[i]);
		vector<ll> ans;
		for (int i=1; i<=n; i++) {
			bool flag = true;
			for (int j=0; j<m; j++) if (i%ng[j]==0) {
				flag = false;
				break;
			}
			if (flag) {
				ans.push_back(i);
			}
		}
		for (int i=0; i<ans.size(); i++)
			res += (double)ans[i] / (double)ans.size();
		printf("%.10f\n", res);
	}
}