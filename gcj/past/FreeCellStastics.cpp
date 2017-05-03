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
	for (int t=1; t<T+1; t++) {
		int N, Pd, Pg; cin >> N >> Pd >> Pg;
		int d, g;
		bool flag=false;
		for (d=1; d<=N; d++) {
			int Wd=d*Pd;
			if (Wd%100!=0) continue;
			else break;
			for (g=100; g>d; g--) {
				int Wg=g*Pg;
				if (Wg%100!=0) continue;
				if (g-Wg/100>=d-Wd/100&&Wg/100>=Wd/100) {
					flag = true;
					break;
				} else if (g-Wg/100<d-Wd/100&&Wg/100<Wd/100){
					break;
				}
			}
			if (flag) break;
		}
		if (flag) cout << "Case #" << t << ": Possible" << endl;
		else cout << "Case #" << t << ": Broken" << endl;
	}
}
