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

class WidgetRepairs {
   public:
   int days(vector <int> arrivals, int numPerDay)
  {
	int count = 0, sum = 0, i = 0;
	while (i<arrivals.size()) {
		sum += arrivals[i];
		if (sum == 0) {
			i++;
			continue;
		} else {
			sum -= numPerDay;
		}
		if (sum < 0) sum = 0;
		count++; i++;
	}
	while (sum > 0) {
		sum -= numPerDay;
		count++;
	}
	return count;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 0, 0, 4, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 6; verify_case(0, Arg2, days(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 0, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 0; verify_case(1, Arg2, days(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, days(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 27, 0, 0, 0, 0, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 4; verify_case(3, Arg2, days(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 15; verify_case(4, Arg2, days(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
WidgetRepairs ___test;
___test.run_test(-1);
}
// END CUT HERE 
