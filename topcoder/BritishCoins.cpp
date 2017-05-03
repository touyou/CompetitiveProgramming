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

// pound = 240 pence
// shilling = 12 pence

class BritishCoins {
   public:
   vector <int> coins(int pence)
  {
	vector <int> res(3);
	if (pence >= 240) {
		res[0] = pence/240;
		pence -= pence/240*240;
	} else {
		res[0] = 0;
	}
	if (pence >= 12) {
		res[1] = pence/12;
		pence -= pence/12*12;
	} else {
		res[1] = 0;
	}
	res[2] = pence;
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 533; int Arr1[] = { 2,
  4,
  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, coins(Arg0)); }
	void test_case_1() { int Arg0 = 0; int Arr1[] = { 0,
  0,
  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, coins(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = { 0,
  0,
  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, coins(Arg0)); }
	void test_case_3() { int Arg0 = 4091; int Arr1[] = { 17,
  0,
  11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, coins(Arg0)); }
	void test_case_4() { int Arg0 = 10000; int Arr1[] = { 41,
  13,
  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, coins(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BritishCoins ___test;
___test.run_test(-1);
}
// END CUT HERE 
