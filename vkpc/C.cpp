#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int dfs(int i, int m, int n, int sum, int cnt, int umb[]) {
	if (sum==n) return cnt;
	if (i==m) return INT_MAX;
	return min(dfs(i+1,m,n,sum+umb[i],cnt+1,umb),dfs(i+1,m,n,sum,cnt,umb));
}
int main() {
	int m, n;
	scanf("%d%d",&m,&n);
	int umb[m];
	for (int i=0; i<m; i++) scanf("%d",&umb[i]);
	sort(umb, umb+m);
	int res = dfs(0,m,n,0,0,umb);
	if (res==INT_MAX) printf("NA\n");
	else printf("%d\n", res);
}