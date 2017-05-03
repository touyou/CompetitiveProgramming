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

class SquareSeries {
   public:
   string completeIt(string pattern, int lastLength)
  {
	if (pattern.length() > lastLength) 
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "W?B"; int Arg1 = 2; string Arg2 = "WB"; verify_case(0, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "?"; int Arg1 = 5; string Arg2 = "BWBWB"; verify_case(1, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BWBBBBW?WB"; int Arg1 = 10; string Arg2 = "..."; verify_case(2, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BWBWBW?WBWBWBW"; int Arg1 = 15; string Arg2 = "BWBWBWBBWBWBWBWBW"; verify_case(3, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WBWBWBWBWBWWBB?W"; int Arg1 = 1; string Arg2 = "WBWBWBWBWBWWBBBBBBBBBBBWW"; verify_case(4, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "?WBWBWBBB"; int Arg1 = 3; string Arg2 = "..."; verify_case(5, Arg2, completeIt(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SquareSeries ___test;
___test.run_test(-1);
}
// END CUT HERE 
