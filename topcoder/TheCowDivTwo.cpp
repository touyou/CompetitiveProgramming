// BEGIN CUT HERE
// PROBLEM STATEMENT
// Farmer John had N cows numbered 0 to N-1. One day he saw K 
// cows running away from his farm. Fox Brus computed the sum 
// of the numbers of the escaped cows. She only told John 
// that the sum was divisible by N.
// 
// 
// Your task is to help John by counting the number of 
// possible sets of escaped cows. This number may be very 
// big, so return it modulo 1,000,000,007.
// 
// DEFINITION
// Class:TheCowDivTwo
// Method:find
// Parameters:int, int
// Returns:int
// Method signature:int find(int N, int K)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1,000, inclusive.
// -K will be between 1 and 47, inclusive.
// -K will be less than or equal to N.
// 
// 
// EXAMPLES
// 
// 0)
// 7
// 4
// 
// Returns: 5
// 
// 7 cows are numbered 0 to 6 and 4 of them run away. 
// Possible sets of escaped cows are {0, 1, 2, 4}, {0, 3, 5, 
// 6}, {1, 2, 5, 6}, {1, 3, 4, 6}, {2, 3, 4, 5}.
// 
// 1)
// 1
// 1
// 
// Returns: 1
// 
// 
// 
// 2)
// 58
// 4
// 
// Returns: 7322
// 
// 
// 
// 3)
// 502
// 7
// 
// Returns: 704466492
// 
// 
// 
// 4)
// 1000
// 47
// 
// Returns: 219736903
// 
// 
// 
// END CUT HERE
#line 73 "TheCowDivTwo.cpp"
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

class TheCowDivTwo {
	public:
	int find(int N, int K) {
		vector<int> cows;
		int count = 0;
		for (int i=0; i<N; i++) {
			cow.push_back(i);
		}
		for (int j=0; j<N; j++) {
			;
		}
		return count;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 5; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 4; int Arg2 = 7322; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 502; int Arg1 = 7; int Arg2 = 704466492; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 47; int Arg2 = 219736903; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheCowDivTwo __test;
	__test.run_test(-1);
}
// END CUT HERE
