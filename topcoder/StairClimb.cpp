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

class StairClimb {
   public:
   int stridesTaken(vector <int> flights, int stairsPerStride)
  {
  	int ans = 0;
	for (int i=0; i<flights.size(); i++) {
		if (flights[i]%stairsPerStride == 0) {
			ans += flights[i]/stairsPerStride;
		} else {
			ans += flights[i]/stairsPerStride+1;
		}
		if (i != 0 && i != flights.size()) ans += 2;
	}
	return ans;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(0, Arg2, stridesTaken(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {15,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 18; verify_case(1, Arg2, stridesTaken(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,11,9,13,8,30,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 44; verify_case(2, Arg2, stridesTaken(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
StairClimb ___test;
___test.run_test(-1);
}
// END CUT HERE 
