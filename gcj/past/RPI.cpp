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
typedef vector<string> ves;
typedef vector<vec> mat;
// const
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main() {
	int T; cin >> T;
	for (int ix=1; ix<=T; ix++) {
		int N; cin >> N;
		ves sc(N);
		for (int i=0; i<N; i++)	cin >> sc[i];
		vector<double> team(N, 0.0), owp(N);
		for (int i=0; i<N; i++) {
			double won=0, game=0, awp=0.0;
			int c=0;
			for (int j=0; j<N; j++) {
				if (sc[i][j] == '1') won++;
				else if (sc[i][j] == '.') continue;
				double w=0, g=0;
				for (int k=0; k<N; k++) {
					if (k==i) continue;
					else if (sc[j][k]=='1') w++;
					else if (sc[j][k]=='.') continue;
					g++;
				}
				c++;
				awp += w/g;
				game++;
			}
			owp[i] = awp/c;
			team[i] += won/game*0.25+awp/c*0.5;
		}
		printf("Case #%d:\n",ix);
		for (int i=0; i<N; i++) {
			double aowp=0;
			int c=0;
			for (int j=0; j<N; j++) {
				if (sc[i][j]=='.') continue;
				aowp += owp[j];
				c++;
			}
			team[i] += aowp/c*0.25;
			printf("%g\n", team[i]);
		}
	}
}
