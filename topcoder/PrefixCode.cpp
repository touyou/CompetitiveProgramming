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

class PrefixCode {
   public:
   string isOne(vector <string> words)
  {
	string tmp; vector<int> count(words.size(), 0); bool b = true;
	for (int i=0; i<words.size(); i++) {
		tmp = words[i];
		for (int j=0; j<words.size(); j++) {
			if (i == j) {
				continue;
			} else if (tmp.length() > words[j].length()) {
				continue;
			} else {
				for (int k=0; k<tmp.length(); k++) {
					if (tmp[k] != words[j][k]) b = false;
				}
				if (!b) {
					b = true;
					continue;
				}
				count[i]++;
			}
		}
	}
	int p = -1;
	for (int i=0; i<words.size(); i++) {
		if (count[i] != 0) {
			p = i;
			break;
		}
	}
	stringstream ss;
	if (p != -1) {
		ss << p;
		tmp = "No, "+ss.str();
	} else {
		tmp = "Yes";
	}
	return tmp;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"trivial"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, isOne(Arg0)); }
	void test_case_1() { string Arr0[] = {"10001", "011", "100", "001", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No, 2"; verify_case(1, Arg1, isOne(Arg0)); }
	void test_case_2() { string Arr0[] = {"no", "nosy", "neighbors", "needed"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No, 0"; verify_case(2, Arg1, isOne(Arg0)); }
	void test_case_3() { string Arr0[] = {"1010", "11", "100", "0", "1011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(3, Arg1, isOne(Arg0)); }
	void test_case_4() { string Arr0[] = {"No", "not"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, isOne(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrefixCode ___test;
___test.run_test(-1);
}
// END CUT HERE 
