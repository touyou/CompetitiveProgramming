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

class Justifier {
   public:
   vector <string> justify(vector <string> textIn)
  {
	int longest = 0, size;
	for (int i=0; i<textIn.size(); i++) {
		size = textIn[i].length();
		longest = max(longest, size);
	}
	for (int i=0; i<textIn.size(); i++) {
		if (textIn[i].length() < longest) {
			reverse(textIn[i].begin(), textIn[i].end());
			textIn[i].resize(longest, ' ');
			reverse(textIn[i].begin(), textIn[i].end());
		}
	}
	return textIn;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","TOMMY","JIM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "  BOB",  "TOMMY",  "  JIM" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, justify(Arg0)); }
	void test_case_1() { string Arr0[] = {"JOHN","JAKE","ALAN","BLUE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "JOHN",  "JAKE",  "ALAN",  "BLUE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, justify(Arg0)); }
	void test_case_2() { string Arr0[] = {"LONGEST","A","LONGER","SHORT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "LONGEST",  "      A",  " LONGER",  "  SHORT" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, justify(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Justifier ___test;
___test.run_test(-1);
}
// END CUT HERE 
