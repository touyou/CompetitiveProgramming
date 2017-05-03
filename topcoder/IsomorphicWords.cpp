#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

struct mat {
	char c, m;
};

class IsomorphicWords {
public:
	mat search(vector<mat> w, mat x) {
		for (int i=0; i<w.size(); i++) {
			if (w[i].c==x.c) return w[i];
			else if (w[i].m==x.m) return w[i];
		}
		mat ng;
		ng.c = '0';
		ng.m = '0';
		return ng;
	}
  int countPairs( vector <string> words ) {
    int result = 0;
	int len = words[0].length();
	for (int i=0; i<words.size()-1; i++) {
		for (int j=i+1; j<words.size(); j++) {
			vector<mat> ism;
			bool flag = true;
			for (int k=0; k<len; k++) {
				mat x;
				x.c = words[i][k];
				x.m = words[j][k];
				mat tmp = search(ism, x);
				if (tmp.c=='0') {
					ism.push_back(x);
				} else if (x.c!=tmp.c||x.m!=tmp.m) {
					flag = false;
					break;
				}
			}
			if (flag) {
			//	cout << words[i] << " " << words[j] << endl;
				result++;
			}
		}
	}
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abca", "zbxz", "opqr"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"aa", "ab", "bb", "cc", "cd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countPairs(Arg0)); }
	void test_case_2() { string Arr0[] = { "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
  "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
  "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, countPairs(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  IsomorphicWords ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
