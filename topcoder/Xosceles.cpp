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

class Xosceles {
   public:
   vector <string> draw(int xCount)
  {
	vector<string> ans;
	bool b = false;
	int c = 0;
	for (int i=1; c<xCount; i+=2) {
		c += i;
		if (c > xCount) {
			b = true;
			break;
		}
	}
	int n = 0;
	c = 0;
	if (b) {
		for (int i=2; c<xCount; i+=2) {
			c+=i;
			n=i;
			if (c > xCount) {
				b = false;
				break;
			}
		}
		if (b) {
			for (int i=n; i>1; i-=2) {
				string tmp = "";
				for (int j=0; j<(n-i)/2; j++) tmp += '.';
				for (int j=0; j<i; j++) tmp += 'X';
				for (int j=0; j<(n-i)/2; j++) tmp += '.';
				ans.push_back(tmp);
			}
		}
	} else {
		for (int i=1; c<xCount; i+=2) {
			c+=i;
			n=i;
		}
		for (int i=n; i>0; i-=2) {
			string tmp = "";
			for (int j=0; j<(n-i)/2; j++) tmp += '.';
			for (int j=0; j<i; j++) tmp += 'X';
			for (int j=0; j<(n-i)/2; j++) tmp += '.';
			ans.push_back(tmp);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = {".X.", "XXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = {".XX.", "XXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { int Arg0 = 16; string Arr1[] = {"...X...", "..XXX..", ".XXXXX.", "XXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }
	void test_case_3() { int Arg0 = 18; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, draw(Arg0)); }
	void test_case_4() { int Arg0 = 100; string Arr1[] = {".........X.........", "........XXX........", ".......XXXXX.......", "......XXXXXXX......", ".....XXXXXXXXX.....", "....XXXXXXXXXXX....", "...XXXXXXXXXXXXX...", "..XXXXXXXXXXXXXXX..", ".XXXXXXXXXXXXXXXXX.", "XXXXXXXXXXXXXXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, draw(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Xosceles ___test;
___test.run_test(-1);
}
// END CUT HERE 
