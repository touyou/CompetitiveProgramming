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

class FixedPointTheorem {
   public:
   double cycleRange(double R)
  {
	double X = 0.25;
	double max_x=0, min_x=1, res;
	for (int i=0; i<200000; i++) {
		X = R*X*(1-X);
	}
	for (int i=0; i<1000; i++) {
		X = R*X*(1-X);
		max_x = max(max_x, X);
		min_x = min(min_x, X);
	}
	res = max_x - min_x;
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = 0.1; double Arg1 = 0.0; verify_case(0, Arg1, cycleRange(Arg0)); }
	void test_case_1() { double Arg0 = 3.05; double Arg1 = 0.14754098360655865; verify_case(1, Arg1, cycleRange(Arg0)); }
	void test_case_2() { double Arg0 = 3.4499; double Arg1 = 0.4175631735867292; verify_case(2, Arg1, cycleRange(Arg0)); }
	void test_case_3() { double Arg0 = 3.55; double Arg1 = 0.5325704489850351; verify_case(3, Arg1, cycleRange(Arg0)); }
	void test_case_4() { double Arg0 = 3.565; double Arg1 = 0.5454276003030636; verify_case(4, Arg1, cycleRange(Arg0)); }
	void test_case_5() { double Arg0 = 3.5689; double Arg1 = 0.5489996297493569; verify_case(5, Arg1, cycleRange(Arg0)); }
	void test_case_6() { double Arg0 = 3.00005; double Arg1 = 0.004713996108955176; verify_case(6, Arg1, cycleRange(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FixedPointTheorem ___test;
___test.run_test(-1);
}
// END CUT HERE 
