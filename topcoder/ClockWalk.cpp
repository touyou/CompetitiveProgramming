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

class ClockWalk {
   public:
   int finalPosition(string flips)
  {
	int time = 12;
	for (int i=0; i<flips.length(); i++) {
		if (flips[i] == 'h') {
			time += i+1;
			while (time > 12) {
				time -= 12;
			}
		} else if (flips[i] == 't') {
			time -= (i+1);
			while (time < 1) {
				time += 12;
			}
		}
	}
	return time;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hhthh"; int Arg1 = 9; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "hhtht"; int Arg1 = 11; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "hthth"; int Arg1 = 3; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "hthhhhh"; int Arg1 = 12; verify_case(3, Arg1, finalPosition(Arg0)); }
	void test_case_4() { string Arg0 = "hthhthtththhtttthttthhhthtttthh"; int Arg1 = 6; verify_case(4, Arg1, finalPosition(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ClockWalk ___test;
___test.run_test(-1);
}
// END CUT HERE 
