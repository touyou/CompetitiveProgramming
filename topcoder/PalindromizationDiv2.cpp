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
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n)  for(int i=0;i<(n);i++)

class PalindromizationDiv2 {
   public:
   int getMinimumCost(int X)
  {
	stringstream ss;
	ss<<X;
	string str=ss.str();
	if (str.length()==1) return 0;
	string tmp="",tmp2="";
	REP(i,str.length()/2) tmp += str[i];
	reverse(ALL(tmp));
	if (str.length()%2==0) {
		for(int i=tmp.length(); i<str.length(); i++) tmp2+=str[i];
	} else {
		for(int i=tmp.length()+1; i<str.length(); i++) tmp2+=str[i];
	}
	cout << tmp << endl;
	cout << tmp2 << endl;
	stringstream ss2, ss3;
	ss2.str(tmp); ss3.str(tmp2);
	int num,num2;
	ss2>>num;ss3>>num2;
	return abs(num-num2);
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 3; verify_case(0, Arg1, getMinimumCost(Arg0)); }
	void test_case_1() { int Arg0 = 12321; int Arg1 = 0; verify_case(1, Arg1, getMinimumCost(Arg0)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 4; verify_case(2, Arg1, getMinimumCost(Arg0)); }
	void test_case_3() { int Arg0 = 2011; int Arg1 = 9; verify_case(3, Arg1, getMinimumCost(Arg0)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; verify_case(4, Arg1, getMinimumCost(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PalindromizationDiv2 ___test;
___test.run_test(-1);
}
// END CUT HERE 
