// #include <cstdio>
// #include <set>
// #include <vector>
// using namespace std;

// set<int> solve(vector<int> dp[], vector<int> map[], int n, set<int> res) {
	// if (dp[n].size() == 0) return res;
	// for (int i=0; i<dp[n].size(); i++) {
		// for (int j=0; j<map[dp[n][i]].size(); j++) {
			// if (res.count(map[dp[n][i]][j]) == 0) {
				// res.insert(map[dp[n][i]][j]);
				// res = solve(dp, map, map[dp[n][i]][j], res);
			// }
		// }
	// }
	// return res;
// }

// int main() {
	// int n, m;
	// while (scanf("%d%d", &n, &m)) {
		// if (n==0&&m==0) break;
		// vector<int> dp[n], map[m];
		// for (int i=0; i<m; i++) {
			// int k, num;
			// scanf("%d", &k);
			// for (int j=0; j<k; j++) {
				// scanf("%d", &num);
				// dp[num].push_back(i);
				// map[i].push_back(num);
			// }
		// }
		// set<int> res;
		// res.insert(0);
		// res = solve(dp, map, 0, res);
		// printf("%d\n", res.size());
	// }
// }
