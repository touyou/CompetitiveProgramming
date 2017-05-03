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
		int L,t,N,C; cin >> L >> t >> N >> C;
		vec a(N);
		for (int i=0; i<C; i++) {
			int tmp; cin >> tmp;
			for (int j=i; j<N; j+=C) a[j] = tmp;
		}
		ll time=0;
		bool flag = true;
		for (int i=0; i<N; i++) {
			if (time+a[i]*2 < t) {
				time += a[i]*2;
			} else if (flag&&L!=0) {
				int tmp = t-time;
				time += tmp+(a[i]-tmp/2);
				flag = false;
				L--;
			} else if (L!=0) {
				time += a[i];
				L--;
			} else {
				time += a[i]*2;
			}
		}
		printf("Case #%d: %lld\n", ix,time);
	}
}
