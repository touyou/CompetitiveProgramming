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

class StrangeComputer {
   public:
   int setMemory(string mem)
  {
	int ans = 0, j;
	char tmp;
	reverse(mem.begin(), mem.end());
	for (int i=0; i<mem.length(); i++) {
		if (mem[0] == '0') tmp = '1';
		else tmp = '0';
		for (j=0; j<mem.length(); j++) {
			if (mem[j] != '0') break;
		}
		if (j == mem.length()) break;
		for (j=0; j<mem.length(); j++) {
			if (mem[j] == tmp) break;
			mem[j] = tmp;
		}
		cout << mem << endl;
		ans++;
	}
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0011"; int Arg1 = 1; verify_case(0, Arg1, setMemory(Arg0)); }
	void test_case_1() { string Arg0 = "000"; int Arg1 = 0; verify_case(1, Arg1, setMemory(Arg0)); }
	void test_case_2() { string Arg0 = "0100"; int Arg1 = 2; verify_case(2, Arg1, setMemory(Arg0)); }
	void test_case_3() { string Arg0 = "111000111"; int Arg1 = 3; verify_case(3, Arg1, setMemory(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
StrangeComputer ___test;
___test.run_test(-1);
}
// END CUT HERE 
