#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <ctime>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 1e-9
#define PI 3.14159265358979

class MinCostPalindrome {
public:
   int getMinimum( string s, int oCost, int xCost ) {
	string rev=s;
	reverse(rev.begin(), rev.end());
	int res=0;
	for (int i=0; i<s.length(); i++) {
		if (s[i]=='?'&&rev[i]=='?') res+=min(oCost,xCost);
		else if (s[i]=='?'&&rev[i]=='o') res+=oCost;
		else if (s[i]=='?'&&rev[i]=='x') res+=xCost;
		else if (rev[i]!='?'&&s[i]!=rev[i]) return -1;
	}
	return res;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string s                  = "oxo?xox?";
			int oCost                 = 3;
			int xCost                 = 5;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "x??x";
			int oCost                 = 9;
			int xCost                 = 4;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "ooooxxxx";
			int oCost                 = 12;
			int xCost                 = 34;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "oxoxooxxxxooxoxo";
			int oCost                 = 7;
			int xCost                 = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "?o";
			int oCost                 = 6;
			int xCost                 = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "????????????????????";
			int oCost                 = 50;
			int xCost                 = 49;
			int expected__            = 980;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string s                  = "o??oxxo?xoox?ox??x??" ;
			int oCost                 = 3;
			int xCost                 = 10;
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
