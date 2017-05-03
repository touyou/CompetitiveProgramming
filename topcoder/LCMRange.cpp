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

class LCMRange {
   public:
int calc_gcj(int a, int b) {
	int A=0, B=0;
	if (a == max(a,b)) {
		A = a;
		B = b;
	} else {
		A = b;
		B = a;
	}
	if (A == B) return A;
	else return calc_gcj(B,A-B);
	return -1;
}
   int lcm(int first, int last)
  {
	vector <int> num;
	for (int i=first; i<=last; i++) {
		num.push_back(i);
	}
	for (int i=0; i<num.size(); i++) {
		for (int j=num.size()-1; j>i; j--) {
			// if (num[j]%num[i] == 0) num[j] /= num[i];
			int g = calc_gcj(num[i], num[j]);
			if (g != -1) num[j] /= g;
		}
	}
	int res = 1;
	for (int i=0; i<num.size(); i++) res *= num[i];
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 60; verify_case(0, Arg2, lcm(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 20; verify_case(1, Arg2, lcm(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 12; int Arg2 = 27720; verify_case(2, Arg2, lcm(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LCMRange ___test;
___test.run_test(-1);
}
// END CUT HERE 
