#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};	

using namespace std;


class Islands {
public:
	vector<string> map;
	int dfs(int ny, int nx) {
		map[ny][nx] = '-';	
		int res=0, xlen=map[0].length(), ylen=map.size();
		for (int i=0; i<4; i++) {
			if (nx+dx[i]>=0&&nx+dx[i]<xlen&&
					ny+dy[i]>=0&&ny+dy[i]<ylen&&
					map[ny+dy[i]][nx+dx[i]]=='#') {
				res += dfs(ny+dy[i], nx+dx[i]);
			} else if (nx+dx[i]>=0&&nx+dx[i]<xlen&&
					ny+dy[i]>=0&&ny+dy[i]<ylen&&
					map[ny+dy[i]][nx+dx[i]]=='.')	{
				res++;
			}
		}
		return res;
	}
  int beachLength( vector <string> kingdom ) {
    int res = 0;
	map = kingdom;
	for (int i=0; i<map.size(); i++) {
		for (int j=0; j<map[i].length(); j++) {
			if (map[i][j] == '#') res += dfs(i, j);
		}
	}
    return res;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#...#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, beachLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"..#.##", 
 ".##.#.", 
 "#.#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, beachLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"#...#.....",
 "##..#...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(2, Arg1, beachLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"....#.",
 ".#....",
 "..#..#",
 "####.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, beachLength(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  Islands ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
