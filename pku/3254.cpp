#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 100000000
using namespace std;
typedef long long ll;
int m, n;
int mask;
int mp[12][12];
ll dp[144][1<<12];
ll solve(int pos, int bit) {
  int y=pos%n, x=pos/n;
  if (pos==m*n) return 1;
  ll res = dp[pos][bit];
  if (res == -1) {
	res = 0;
	if (!mp[x][y]) {
	  res = (res + solve(pos+1, (bit<<1)&mask)) % mod;
	} else {
	  res = (res + solve(pos+1, (bit<<1)&mask)) % mod;
	  if (!(y!=0 && bit&1) && !((bit>>(n-1))&1)) {
		res = (res + solve(pos+1, ((bit<<1)|1)&mask)) % mod;
	  }
	}
  }
  return (dp[pos][bit]=res);
}
int main() {
  scanf("%d%d",&m,&n);
  for (int i=0; i<m; i++) {
	for (int j=0; j<n; j++) {
	  scanf("%d",&mp[i][j]);
	}
  }
  mask = (1<<n) - 1;
  memset(dp, -1, sizeof(dp));
  printf("%lld\n",solve(0,0));
}
