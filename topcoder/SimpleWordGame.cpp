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
#define SORT(c) sort((c).begin(),(c).end())
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(c) (c).begin(),(c).end()
#define SZ(c) (c).size()
typedef vector<string> vs;

class SimpleWordGame {
   public:
   int points(vector <string> player, vector <string> dictionary)
  {
	SORT(player); SORT(dictionary);
	vs::iterator it=unique(ALL(player)); player.erase(it, player.end());
	int res = 0;
	REP(i,SZ(player)) {
		bool flag=false;
		REP(j,SZ(dictionary)) {
			if (player[i]==dictionary[j]) {
				flag = true;
				break;
			}
		}
		if (flag) res+=player[i].length()*player[i].length();
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "apple", "orange", "strawberry" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 136; verify_case(0, Arg2, points(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "apple" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, points(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "orange", "orange" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(2, Arg2, points(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "lidi", "o", "lidi", "gnbewjzb", "kten",
  "ebnelff", "gptsvqx", "rkauxq", "rkauxq", "kfkcdn"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "nava", "wk", "kfkcdn", "lidi", "gptsvqx",
  "ebnelff", "hgsppdezet", "ulf", "rkauxq", "wcicx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 186; verify_case(3, Arg2, points(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SimpleWordGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
