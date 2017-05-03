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
int solve(ll n) {
	int res = 0;
	ll bit=1;
	char buff[65];
	for (int i=0; i<65; i++) {
		if (n&bit) buff[i]='1';
		else buff[i]='0';
		bit<<=1;
	}
	int c=64;
	while (buff[c]=='0'&&c>=0) c--;
	bool flag = false;
	for (int i=0; i<=c; i++) {
		if (flag) {
			if (buff[i]=='0') {
				res++;
				flag = true;
			} else if (buff[i]=='1') {
				res+=2;
				flag=true;
			}
		} else {
			if (buff[i]=='0') {
				res+=2;
				flag=true;
			} else if (buff[i]=='1') {
				res++;
			}
		}
	}
	if (flag) {
		res -= 2;
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