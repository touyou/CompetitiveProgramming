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

class RPG {
   public:
   vector <int> dieRolls(vector <string> dice)
  {
	vector <int> ans(3, 0);
	double tmp = 0.0;
	string f, l;
	int j, fn, ln;
	for (int i=0; i<dice.size(); i++) {
		f=""; l=""; j=0;
		while (dice[i][j] != 'd') {
			f += dice[i][j];
			j++;
		}
		j++;
		while (j < dice[i].length()) {
			l += dice[i][j];
			j++;
		}
		stringstream fs,ls;
		fs.str(f);
		fs >> fn;
		ls.str(l);
		ls >> ln;
		ans[0] += fn;
		ans[1] += fn*ln;
		tmp += 1.0*fn*(ln+1)/2;
	}
	ans[2] = (int)tmp;
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"3d6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  18,  10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, dieRolls(Arg0)); }
	void test_case_1() { string Arr0[] = {"3d4","1d6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  18,  11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, dieRolls(Arg0)); }
	void test_case_2() { string Arr0[] = {"6d5","10d10","10d20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 26,  330,  178 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, dieRolls(Arg0)); }
	void test_case_3() { string Arr0[] = {"1d2","2d2","4d2","6d2","8d2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 21,  42,  31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, dieRolls(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
RPG ___test;
___test.run_test(-1);
}
// END CUT HERE 
