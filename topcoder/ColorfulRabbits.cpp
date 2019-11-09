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


using namespace std;


class ColorfulRabbits {
public:
  int getMinimum( vector <int> replies ) {
    int res = 0;
	sort(replies.begin(), replies.end());
	for (int i=0; i<replies.size(); i++) {
		res += replies[i] + 1;
		int j;
		for (j=i+1; j<i+1+replies[i] && j<replies.size(); j++)
		   if (replies[i] != replies[j]) break;
		i = j - 1;
	}	
    return res;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(2, Arg1, getMinimum(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  ColorfulRabbits ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
