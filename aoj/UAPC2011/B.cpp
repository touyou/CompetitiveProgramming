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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
/*ce*/
int main() {
	int N;
	while (cin>>N&&N!=0) {
		map<string, int> m;
		vs names;
		for (int i=0; i<N; i++) {
			string name;int w,t;cin>>name>>w>>t;
			names.PB(name);
			int h=t/100;
			int m=t-h*100;
			m[name]=w*1440+h*60+m;
		}
		int q; cin >> q;
		vs f(q);
		for (int i=0; i<q; i++) {
			cin>>f[i];
		}
		vi look;
		bool flag = false;
		for (int i=0; i<q; i++) {
			if (look.empty()) {
				look.PB(m[f[i]]);
			} else {
				for (int j=0; j<SZ(look); j++) {
					if ((m[look[j]]<=m[f[i]]&&m[look[j]]+30>=m[f[i]])||(m[look[j]]<=m[f[i]]+30&&m[look[j]]>=m[f[i]])) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
		if (flag) {
			cout << -1 << endl;
			continue;
		}
		flag = false;
		for (int i=0; i<names.size(); i++) {
			for (int j=0; j<SZ(look); j++) {
				if ((m[look[j]]<=m[names[i]]&&m[look[j]]+30>=m[names[i]])||(m[look[j]]<=m[names[i]]+30&&m[look[j]]>=m[names[i]])) {
					continue;
				} else {
					flag = true;
				}
			}
			if (flag) {
				look.PB(SZ(names));
				flag=false;
			}
		}
		cout << SZ(look) << endl;
	}
}
