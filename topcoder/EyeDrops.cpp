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

class EyeDrops {
   public:
   double closest(int sleepTime, int k)
  {
	long double res;
	long double day = 24*60;
	sleepTime *= 60;
	long double act = day-sleepTime;
	if (day/k >= sleepTime) {
		res = day/k;
	} else {
		res = act/(k-1);
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 2; double Arg2 = 720.0; verify_case(0, Arg2, closest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 3; double Arg2 = 450.0; verify_case(1, Arg2, closest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 1; double Arg2 = 1440.0; verify_case(2, Arg2, closest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 8; double Arg2 = 128.57142857142856; verify_case(3, Arg2, closest(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
EyeDrops ___test;
___test.run_test(-1);
}
// END CUT HERE 
