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

class SoldierLabeling {
   public:
   int count(int n, int lowerBound, int upperBound)
  {
	int lower = (int)pow(10.0, lowerBound-1)-1; int upper = (int)pow(10.0, upperBound)-1;
	lower=min(n,lower); upper=min(n,upper);
	cout << lower << " " << upper << endl;
	return upper-lower;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 2; int Arg3 = 90; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 31; int Arg1 = 2; int Arg2 = 3; int Arg3 = 22; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 8; int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10000000; int Arg1 = 8; int Arg2 = 8; int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2718317; int Arg1 = 3; int Arg2 = 7; int Arg3 = 2718218; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SoldierLabeling ___test;
___test.run_test(-1);
}
// END CUT HERE 
