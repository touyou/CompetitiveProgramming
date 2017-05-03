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

class TheBeauty {
   public:
   int find(int n)
  {
	stringstream ss; ss<<n; string st=ss.str();
	set<char> s;
	for (int i=0; i<st.length(); i++) s.insert(st[i]);
	return s.size();
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 123456789; int Arg1 = 9; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 932400154; int Arg1 = 7; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheBeauty ___test;
___test.run_test(-1);
}
// END CUT HERE 
