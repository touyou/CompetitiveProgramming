#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main() {
	int w,n,c=1;
	while (scanf("%d",&w)) {
		if (w==0) break;
		scanf("%d",&n);
		int W[n],V[n];
		for (int i=0; i<n; i++) scanf("%d%*c%d",&V[i],&W[i]);
		int dp[n+1][w+1];
		int rw=1001,rv=0;
		for (int i=0; i<=w; i++) dp[n][i]=0;
		for (int i=n-1; i>=0; i--) {
			for (int j=0; j<=w; j++) {
				if (W[i]>j) dp[i][j]=dp[i+1][j];
				else {
					int r1=dp[i+1][j],r2=dp[i+1][j-W[i]]+V[i];
					if (r2>=r1) {
						if (rv<r2) {
							rv=r2;
							rw=j;
						} else if (rv==r2) {
							rw=min(rw,j);
						}
						dp[i][j]=r2;
					} else {
						dp[i][j]=r1;
					}
				}
			}
		}
		printf("Case %d:\n%d\n%d\n",c++,rv,rw);
	}
}
