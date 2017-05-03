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

class FourBlocksEasy {
   public:
   int maxScore(vector <string> grid)
  {
	int n=2, m=SZ(grid[0]);
	int score=0;
	REP(j,m) {
		if (j+1<m&&grid[0][j]=='.'&&grid[1][j]=='.'&&grid[0][j+1]=='.'&&grid[1][j+1]=='.') {
			score+=16;
			grid[0][j]=grid[1][j]=grid[0][j+1]=grid[1][j+1]='*';
		}
	}
	REP(i,n) {
		REP(j,m) {
			if (grid[i][j]=='.'||grid[i][j]=='1') {
				score+=1;
				grid[i][j]='1';
			}
		}
	}
	return score;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....1..1..",
 "..1.....1.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"....................",
 "...................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 160; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {".1.........11.........",
 "..1.1......11........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {"......1.....1...1.",
 ".................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 108; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FourBlocksEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
