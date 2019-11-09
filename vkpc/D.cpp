#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main() {
	int n, m; scanf("%d",&n);
	vector<P> chara(n);
	for (int i=0; i<n; i++) scanf("%d%d",&chara[i].first,&chara[i].second);
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (chara[i].first>chara[j].first) swap(chara[i], chara[j]);
			else if (chara[i].first==chara[j].first&&chara[i].second>chara[j].second) swap(chara[i], chara[j]);
		}
	}
	int dp[n+2];
	dp[0]=0;
	dp[1]=chara[0].first+chara[0].second;
	for (int i=2; i<n+1; i++) dp[i]=max(dp[i-1],chara[i-1].first)+chara[i-1].second;
	dp[n+1]=INT_MAX;
	scanf("%d",&m);
	for (int i=0; i<m; i++) {
		int t; scanf("%d",&t);
		printf("%d\n",upper_bound(dp,dp+n+2,t)-dp-1);
	}
}