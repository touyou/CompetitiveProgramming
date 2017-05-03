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
typedef long double ld;
ll solve(int a, int b, int c) {
	ll res=a;
	for (int i=0; i<b; i++) {
		res = (ll)pow((ld)res, (ld)res) % c;
	}
	return res;
}
int main() {
	int t; scanf("%d", &t);
	for (int ix=1; ix<=t; ix++) {
		int a,c,b;
		scanf("%d%d%d",&a,&b,&c);
		printf("Case #%d: %lld\n", ix,solve(a,b,c));
	}
}