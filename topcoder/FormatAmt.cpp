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

class FormatAmt {
   public:
   string amount(int dollars, int cents)
  {
  	stringstream ss;
  	char doll[10];
  	sprintf(doll, "%d", dollars);
  	string s = string(doll);
	reverse(s.begin(), s.end());
	string ans = "";
	for (int i=0; i<s.length(); i++) {
		ans += s[i];
		if(i % 3 == 2 && i+1 < s.length()) {
			ans += ',';
		}
	}
	ans += '$';
	reverse(ans.begin(), ans.end());
	ss << cents;
	string cent = ss.str();
	if (cent.length() == 1) {
		char tmp = cent[0];
		cent[0] = '0';
		cent.push_back(tmp);
	}
	ans += '.'; ans += cent;
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 123456; int Arg1 = 0; string Arg2 = "$123,456.00"; verify_case(0, Arg2, amount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49734321; int Arg1 = 9; string Arg2 = "$49,734,321.09"; verify_case(1, Arg2, amount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 99; string Arg2 = "$0.99"; verify_case(2, Arg2, amount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 249; int Arg1 = 30; string Arg2 = "$249.30"; verify_case(3, Arg2, amount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1; string Arg2 = "$1,000.01"; verify_case(4, Arg2, amount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FormatAmt ___test;
___test.run_test(-1);
}
// END CUT HERE 
