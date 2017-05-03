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
		int R, C; cin >> R >> C;
		ves input(R);
		bool flag=true;
		for (int i=0; i<R; i++) cin >> input[i];
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (input[i][j]=='#') {
					if (i+1<R&&j+1<C&&input[i][j+1]=='#'&&input[i+1][j]=='#'&&input[i+1][j+1]=='#') {
						input[i][j] = '/'; input[i][j+1] = '\\';
						input[i+1][j] = '\\'; input[i+1][j+1] = '/';
						j++;
					} else {
						flag = false;
						break;
					}
				}
			}
			if (!flag) break;
		}
		printf("Case #%d:\n",ix);
		if (flag) {
			for (int i=0; i<R; i++) cout << input[i] << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
}
