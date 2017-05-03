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

class HappyCells {
   public:
   vector <int> getHappy(vector <string> grid)
  {
	vi res(3, 0);
	int dy[8] = {-1,1,-1,1,-1,1,0,0};
	int dx[8] = {-1,-1,0,0,1,1,-1,1};
	REP(i,SZ(grid)) {
		REP(j, SZ(grid[i])) {
			if (grid[i][j]=='.') {
				int dia=0, ort=0;
				REP(k, 8) {
					if (i+dx[k]>=0&&i+dx[k]<SZ(grid)&&j+dy[k]>=0&&j+dy[k]<SZ(grid[0])&&grid[i+dx[k]][j+dy[k]]=='.') {
						if (k==2||k==3||k==6||k==7) ort++;
						else dia++;
					}
				}
				if (ort==0&&dia==0) res[0]++;
				else if (ort==0&&dia!=0) res[1]++;
				else if (ort!=0&&dia==0) res[2]++;
			}
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXX",
"X.X",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getHappy(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getHappy(Arg0)); }
	void test_case_2() { string Arr0[] = {
"XXXXXX",
"X.XXXX",
"XXX.XX",
"X..XXX",
"XXXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getHappy(Arg0)); }
	void test_case_3() { string Arr0[] = {"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getHappy(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
HappyCells ___test;
___test.run_test(-1);
}
// END CUT HERE 
