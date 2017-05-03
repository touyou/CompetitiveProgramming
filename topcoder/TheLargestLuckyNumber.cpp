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

// 4, 7, 44, 47, 74, 77, 444, 447, 474, 477...

class TheLargestLuckyNumber {
   public:
   int find(int n)
  {
	vector <int> res(2), tmp;
	res[0] = 4; res[1] = 7;
	int ten=0, ans=0, a=2;
	for (int i=2; ten<n; i++) {
		ten = (int)pow(10.0, i-1);
		for (int j=0; j<a; j++) {
			tmp.push_back(res[res.size()-1-j]+ten*4);
			tmp.push_back(res[res.size()-1-j]+ten*7);
		}
		for (int j=0; j<tmp.size(); j++) {
			res.push_back(tmp[j]);
		}
		a *= 2;
		sort(res.begin(), res.end());
	}
	for (int i=res.size()-1; i>=0; i--) {
		if (res[i] <= n) {
			ans = res[i];
			break;
		}
	}
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 77; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 75; int Arg1 = 74; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 474747; int Arg1 = 474747; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheLargestLuckyNumber ___test;
___test.run_test(-1);
}
// END CUT HERE 
