#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
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

class UnluckyNumbers {
   public:
   int getCount(vector <int> luckySet, int n)
  {
	sort(luckySet.begin(),luckySet.end());
	int i;
	bool flag=false;
	for (i=0; i<luckySet.size(); i++) {
		if (luckySet[i]==n) {
			flag=true;
			break;
		} else if (luckySet[i]>n) {
			break;
		}
	}
	if (flag) return 0;
	int upper=luckySet[i],lower=0;
	if (i-1>=0) lower=luckySet[i-1];
	int res=0;
	for (int j=lower+1; j<=n; j++) {
		for (int k=n; k<upper; k++) {
			if (j<k) res++;
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 7, 14, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 8, 13, 24, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 40, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 7, 12, 18, 25, 100, 33, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 59; int Arg2 = 1065; verify_case(3, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
UnluckyNumbers ___test;
___test.run_test(-1);
}
// END CUT HERE 
