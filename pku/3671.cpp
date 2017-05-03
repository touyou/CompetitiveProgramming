#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int cows[n];
    for (int i=0; i<n; i++) scanf("%d", &cows[i]);
    int res = INT_MAX;
	int dp[2] = {0, 0};	// 1---iまでの2の個数 2---i+1からの1の個数
    for (int i=0; i<n; i++) if (cows[i]==1) dp[1]++;
	res = min(res, dp[0]+dp[1]);
	for (int i=0; i<n; i++) {
		if (cows[i]==2) {
			dp[0]++;
		} else {
			dp[1]--;
		}
		res = min(res, dp[0]+dp[1]);
	}
    printf("%d\n", res);
}
