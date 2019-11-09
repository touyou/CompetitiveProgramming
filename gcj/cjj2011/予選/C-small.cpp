#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
int cntbit(ll bits) {
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
	return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
int solve(ll n) {
	int res = 0;
	for (int i=0; i<=n/2; i++) {
		ll a = i, b = n - i;
		res = max(res, cntbit(a)+cntbit(b));
	}
	return res;
}
int main() {
	int t; scanf("%d", &t);
	for (int ix=1; ix<=t; ix++) {
		ll n; scanf("%lld", &n);
		printf("Case #%d: %d\n", ix, solve(n));
	}
}