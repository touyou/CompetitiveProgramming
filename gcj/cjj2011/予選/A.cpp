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
struct rsf { int a, b;};
int solve(int m, int c, int w, rsf s[]) {
	// vector<rsf> ns;
	// int res = w;
	// for (int i=0; i<c; i++) {
		// if (ns.empty()) {
			// ns.push_back(s[i]);
		// } else {
			// bool flag = true;
			// for (int j=0; j<ns.size(); j++) {
				// if (ns[j] == s[i]) {
					// ns[j].c++;
					// flag = false;
				// }
			// }
			// if (flag) ns.push_back(s[i]);
		// }
	// }
	// for (int i=0; i<ns.size(); i++) {
		
	// }
	// return res;
	for (int i=c-1; i>=0; i--) {
		if (w<=s[i].b) {
			w = s[i].a + w - 1;
		} else if (w<=s[i].a+s[i].b-1) {
			w -= s[i].b;
		}
	}
	return w;
}
int main() {
	int t;scanf("%d",&t);
	for (int ix=1; ix<=t; ix++) {
		int m, c, w;
		scanf("%d%d%d",&m,&c,&w);
		rsf s[c];
		for (int i=0; i<c; i++) scanf("%d%d",&s[i].a,&s[i].b);
		printf("Case #%d: %d\n", ix, solve(m,c,w,s));
	}
}