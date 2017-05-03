// BEGIN CUT HERE
// END CUT HERE
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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

class KnightsTour {
   public:
   int dfs(vector<string> board, int x, int y, int c) {
   	int dx[] = {-1,1,-2,2,-2,2,-1,1};
	int dy[] = {-2,-2,-1,-1,1,1,2,2};
	board[x][y] = '*';
	for (int i=0; i<8; i++) {
		int mx=x+dx[i];
		int my=y+dy[i];
		if (mx>=0&&mx<8&&my>=0&&my<8&&board[mx][my]=='.') {
			c = min(c, dfs(board,mx,my,c++));
		}
	}
	return c;
   }
   int visitedPositions(vector <string> board)
  {
	int max_row=8, max_col=8, kx, ky;
	for (int i=0; i<max_row; i++) {
		for (int j=0; j<max_col; j++) {
			if (board[i][j]=='K') kx=i; ky=j;
		}
	}
	int ans = dfs(board,kx,ky,1);
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(0, Arg1, visitedPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, visitedPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, visitedPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, visitedPositions(Arg0)); }
	void test_case_4() { string Arr0[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(4, Arg1, visitedPositions(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
KnightsTour ___test;
___test.run_test(-1);
}
// END CUT HERE 
