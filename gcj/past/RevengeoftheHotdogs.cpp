// include
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
// define
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
// int <-> string
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
// typedef
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
// const
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main() {
	int T; cin >> T;
	for (int ix=1; ix<=T; ix++) {
		int C, D; cin >> C >> D;
		pair<int,int> pd[C];
		for (int i=0; i<C; i++) {
			cin >> pd[i].first >> pd[i].second;
		}
		sort(pd, pd+C);
		double ans=0.0;
		for (int i=0; i<C; i++) {
			int x = pd[i].second/2+1;
			double move = D/x;
			for (int j=0; j<C; j++) {
				if (pd[i].first+move==pd[j].first) pd[j].second++;
			}
			ans += move;
		}
		printf("Case #%d: %g\n",ix,ans);
	}
}
