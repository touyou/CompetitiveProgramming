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

class TheSwap {
   public:
   int findMax(int n, int k)
  {
	stringstream ss; ss<<n; string num=ss.str();
	if (num.size()==1) return -1;
	int res;
	string save=num;
	for (int i=0; i<k; i++) {
		char tmp=num[i];
		int l=i;
		for (int j=num.size()-1; j>i; j--) {
			if (tmp<num[j]) {
				tmp=num[j];
				l=j;
			}
		}
		swap(num[i],num[l]);
	}
	if (save==num) {
		
	}
	stringstream ss2; ss2.str(num);
	ss2>>res;
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16375; int Arg1 = 1; int Arg2 = 76315; verify_case(0, Arg2, findMax(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 432; int Arg1 = 1; int Arg2 = 423; verify_case(1, Arg2, findMax(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 90; int Arg1 = 4; int Arg2 = -1; verify_case(2, Arg2, findMax(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, findMax(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 436659; int Arg1 = 2; int Arg2 = 966354; verify_case(4, Arg2, findMax(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheSwap ___test;
___test.run_test(-1);
}
// END CUT HERE 
