#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
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
typedef vector<int> vec;

int main() {
	int T; cin >> T;
	for (int i=0; i<T; i++) {
		ll ans = 0;
		int n; cin >> n;
		vec x(n), y(n);
		for (int j=0; j<n; j++) cin >> x[j];
		for (int j=0; j<n; j++) cin >> y[j];
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		reverse(y.begin(), y.end());
		for (int j=0; j<n; j++) ans += x[j]*y[j];
		printf("Case #%d: %lld\n",i+1,ans);
	}
}
